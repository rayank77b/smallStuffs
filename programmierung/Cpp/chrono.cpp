#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>

int main() {
    using namespace std::chrono;

    // 1. Zeit messen mit steady_clock
    auto start = steady_clock::now();

    std::this_thread::sleep_for(std::chrono::milliseconds(500));  // künstliche Pause

    auto end = steady_clock::now();
    auto elapsed = duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "1) Gemessene Zeit: " << elapsed.count() << " ms\n";


    // 2. Aktuelles Datum und Uhrzeit mit system_clock
    auto now = system_clock::now();
    std::time_t now_c = system_clock::to_time_t(now);
    std::cout << "2) Aktuelle Zeit: " << std::put_time(std::localtime(&now_c), "%d.%m.%Y %H:%M:%S") << "\n";


    // 3. Timestamp in Sekunden und Millisekunden
    auto now_since_epoch = now.time_since_epoch();
    auto seconds = duration_cast<std::chrono::seconds>(now_since_epoch).count();
    auto millis  = duration_cast<std::chrono::milliseconds>(now_since_epoch).count();

    std::cout << "3) Seit 1970 (Sekunden): " << seconds << "\n";
    std::cout << "   Seit 1970 (Millisekunden): " << millis << "\n";


    // 4. Warten mit präzisem Timer
    std::cout << "4) Warten 1 Sekunde... ";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "fertig.\n";


    // 5. Countdown mit high_resolution_clock (optional, präziser)
    std::cout << "5) Countdown: ";
    auto t1 = high_resolution_clock::now();
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    auto t2 = high_resolution_clock::now();

    auto ms = duration_cast<std::chrono::microseconds>(t2 - t1);
    std::cout << ms.count() << " Mikrosekunden gewartet.\n";

    return 0;
}