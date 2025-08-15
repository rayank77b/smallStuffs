#include <opencv2/opencv.hpp>
#include <opencv2/core/ocl.hpp>
#include <iostream>
#include <iomanip>

// OCL_ICD_VENDORS=/etc/OpenCL/vendors/rusticl.icd OPENCV_OPENCL_DEVICE=:GPU: ./deine_app

static void printOclInfo() {
    std::cout << "OpenCL available (build): " << (cv::ocl::haveOpenCL() ? "YES" : "NO") << "\n";
    std::cout << "OpenCL enabled (runtime): " << (cv::ocl::useOpenCL() ? "YES" : "NO") << "\n";

    if (cv::ocl::haveOpenCL()) {
        cv::ocl::Context ctx;
        if (!ctx.create(cv::ocl::Device::TYPE_GPU))
            ctx.create(cv::ocl::Device::TYPE_ALL);
        if (ctx.ndevices() > 0) {
            cv::ocl::Device dev = ctx.device(0);
            std::cout << "Device:   " << dev.name() << " (" << dev.vendorName() << ")\n";
            std::cout << "Version:  " << dev.version() << "\n";
            std::cout << "Driver:   " << dev.driverVersion() << "\n";
            std::cout << "Type:     " << (dev.isAMD() ? "AMD " : dev.isIntel() ? "Intel " : dev.isNVidia() ? "NVIDIA " : "") 
                      << (dev.type() == cv::ocl::Device::TYPE_GPU ? "GPU" : "OTHER") << "\n";
        }
    }
    std::cout << std::endl;
}

static void overlayText(cv::Mat &img, const std::string &line1, const std::string &line2) {
    int y = 24;
    cv::putText(img, line1, {10, y}, cv::FONT_HERSHEY_SIMPLEX, 0.6, {0,0,0}, 3);
    cv::putText(img, line1, {10, y}, cv::FONT_HERSHEY_SIMPLEX, 0.6, {255,255,255}, 1);
    y += 24;
    cv::putText(img, line2, {10, y}, cv::FONT_HERSHEY_SIMPLEX, 0.6, {0,0,0}, 3);
    cv::putText(img, line2, {10, y}, cv::FONT_HERSHEY_SIMPLEX, 0.6, {255,255,255}, 1);
}

int main(int argc, char** argv) {
    int deviceIndex = 0;
    if (argc >= 2) deviceIndex = std::stoi(argv[1]);

    // OpenCL aktivieren (wenn verfügbar)
    cv::ocl::setUseOpenCL(true);
    printOclInfo();

    // Kamera öffnen
    cv::VideoCapture cap(deviceIndex, cv::CAP_V4L2);
    if (!cap.isOpened()) {
        std::cerr << "Fehler: Kann Kamera " << deviceIndex << " nicht öffnen.\n";
        return 1;
    }
    cap.set(cv::CAP_PROP_FRAME_WIDTH,  640);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);
    // cap.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M','J','P','G'));

    std::cout << "Start: " 
              << cap.get(cv::CAP_PROP_FRAME_WIDTH) << "x"
              << cap.get(cv::CAP_PROP_FRAME_HEIGHT) << " @ "
              << cap.get(cv::CAP_PROP_FPS) << " fps (reported)\n";

    cv::namedWindow("OpenCV + OpenCL", cv::WINDOW_AUTOSIZE);

    bool useOpenCL = cv::ocl::useOpenCL(); // aktueller Modus
    if( useOpenCL ) 
        std::cout << "use OpenCL is true\n";
    else
        std::cout << "use OpenCL is false\n";
    
    cv::TickMeter tm;

    std::cout<< "While loop...\n";
    while (true) {
        cv::Mat frame;
        if (!cap.read(frame) || frame.empty()) {
            std::cerr << "Warnung: leerer Frame.\n";
            break;
        }
        
        tm.reset(); tm.start();
        
        if (useOpenCL) {
            // --- GPU-Pfad via UMat (T-API) ---
            cv::UMat uFrame, uGray, uBlur, uEdges, uBgr;
            frame.copyTo(uFrame);                               // Host→UMat
            cv::cvtColor(uFrame, uGray, cv::COLOR_BGR2GRAY);
            cv::GaussianBlur(uGray, uBlur, cv::Size(7,7), 1.5);
            cv::Canny(uBlur, uEdges, 50, 150);
            cv::cvtColor(uEdges, uBgr, cv::COLOR_GRAY2BGR);
            uBgr.copyTo(frame);                                 // UMat→Host (zum Anzeigen)
        } else {
            // --- CPU-Pfad via Mat ---
            cv::Mat gray, blur, edges;
            cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
            cv::GaussianBlur(gray, blur, cv::Size(7,7), 1.5);
            cv::Canny(blur, edges, 50, 150);
            cv::cvtColor(edges, frame, cv::COLOR_GRAY2BGR);
        }

        tm.stop();
        double ms = tm.getTimeMilli();
        // Overlay: Modus + Zeit + (optional) Device-Name
        std::string line1 = useOpenCL ? "Mode: OpenCL (UMat)" : "Mode: CPU (Mat)";
        std::string line2 = "Frame time: " + std::to_string(ms) + " ms";
        overlayText(frame, line1, line2);
        cv::imshow("OpenCV + OpenCL", frame);
        int key = cv::waitKey(1);
        if (key == 27 || key == 'q') break;                 // ESC/q: Ende
        if (key == 'o') {                                   // o: OpenCL toggle
            useOpenCL = !useOpenCL;
            cv::ocl::setUseOpenCL(useOpenCL);
            printOclInfo();
        }
        if (key == 'i') {                                   // i: Buildinfo
            std::cout << cv::getBuildInformation() << std::endl;
        }
        if (key == 's') {                                   // s: Snapshot
            auto t = std::time(nullptr);
            std::tm tm{}; localtime_r(&t, &tm);
            std::ostringstream fn; fn << "ocl_snap_" << std::put_time(&tm, "%Y%m%d_%H%M%S") << ".png";
            if (cv::imwrite(fn.str(), frame))
                std::cout << "Gespeichert: " << fn.str() << "\n";
        }
    }
    return 0;
}