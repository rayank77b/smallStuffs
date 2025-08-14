#include <opencv2/opencv.hpp>
//#include <opencv2/gpu/gpu.hpp>
#include <iostream>
#include <chrono>
#include <iomanip>

static void printUsage(const char* prog) {
    std::cout << "Usage: " << prog << " [device_index] [width height fps]\n"
              << "  device_index: 0 (default) für /dev/video0\n"
              << "  Beispiel: " << prog << " 0 1280 720 30\n";
}

int main(int argc, char** argv) {
    int device = 0;
    int width  = 0;   // 0 = nicht setzen
    int height = 0;
    double fps = 0.0;

    if (argc >= 2) {
        std::string a = argv[1];
        if (a == "-h" || a == "--help") { printUsage(argv[0]); return 0; }
        device = std::stoi(a);
    }
    if (argc >= 4) {
        width  = std::stoi(argv[2]);
        height = std::stoi(argv[3]);
    }
    if (argc >= 5) {
        fps = std::stod(argv[4]);
    }

    // Öffnen der Kamera (unter Linux oft CAP_V4L2 sinnvoll)
    cv::VideoCapture cap(device, cv::CAP_V4L2);
    if (!cap.isOpened()) {
        std::cerr << "Fehler: Kann Kamera " << device << " nicht öffnen.\n";
        return 1;
    }

    // Optional gewünschte Parameter setzen
    if (width  > 0) cap.set(cv::CAP_PROP_FRAME_WIDTH,  width);
    if (height > 0) cap.set(cv::CAP_PROP_FRAME_HEIGHT, height);
    if (fps    > 0) cap.set(cv::CAP_PROP_FPS,          fps);
    // Optional: MJPG-FourCC für höhere FPS auf vielen Webcams
    // cap.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M','J','P','G'));

    // Tatsächliche Parameter anzeigen
    std::cout << "Geöffnete Kamera: " << device << "\n"
              << "Auflösung: " << cap.get(cv::CAP_PROP_FRAME_WIDTH)
              << "x" << cap.get(cv::CAP_PROP_FRAME_HEIGHT) << "\n"
              << "FPS (reported): " << cap.get(cv::CAP_PROP_FPS) << "\n";

    cv::namedWindow("Webcam", cv::WINDOW_AUTOSIZE);

    using clock = std::chrono::steady_clock;
    auto t0 = clock::now();
    int frames = 0;

    while (true) {
        cv::Mat frame;
        if (!cap.read(frame) || frame.empty()) {
            std::cerr << "Warnung: Leerer Frame / Read-Fehler.\n";
            break;
        }

        // Beispiel: Zeitstempel einblenden
        auto now = std::chrono::system_clock::now();
        std::time_t tt = std::chrono::system_clock::to_time_t(now);
        std::tm tm{};
        localtime_r(&tt, &tm);
        std::ostringstream oss;
        oss << std::put_time(&tm, "%F %T");
        cv::putText(frame, oss.str(), {10, 30}, cv::FONT_HERSHEY_SIMPLEX, 0.8, {255,255,255}, 2);

        cv::imshow("Webcam", frame);
        frames++;

        // einfache Live-FPS-Schätzung
        auto t1 = clock::now();
        double elapsed = std::chrono::duration<double>(t1 - t0).count();
        if (elapsed >= 1.0) {
            double live_fps = frames / elapsed;
            cv::setWindowTitle("Webcam", "Webcam  |  FPS: " + std::to_string(live_fps));
            t0 = t1; frames = 0;
        }

        // Tastatur:
        //  q / ESC  -> beenden
        //  s        -> Screenshot speichern
        int key = cv::waitKey(1);
        if (key == 'q' || key == 27) break;
        if (key == 's') {
            std::ostringstream fn;
            fn << "snapshot_" << std::put_time(&tm, "%Y%m%d_%H%M%S") << ".png";
            if (cv::imwrite(fn.str(), frame)) {
                std::cout << "Gespeichert: " << fn.str() << "\n";
            } else {
                std::cerr << "Konnte Snapshot nicht speichern.\n";
            }
        }
    }

    return 0;
}
