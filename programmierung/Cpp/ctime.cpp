#include <iostream>
#include <ctime>

int main() {
    std::time_t now = std::time(nullptr);           // aktuelle Zeit holen
    std::cout << "Zeitstempel (Sekunden seit 1970): " << now << std::endl;
    std::tm* local = std::localtime(&now);          // in lokale Zeit konvertieren
    std::cout << "Lokale Zeit: "<< std::asctime(local);               // als String ausgeben

    // zeit messen
    std::clock_t start = std::clock();
    // Beispiel-Code zum Messen
    for (volatile int i = 0; i < 100000000; ++i);
    std::clock_t end = std::clock();
    double seconds = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Verstrichene Zeit: " << seconds << " Sekunden\n";

    // datum und uhrzeit formatieren
    now = std::time(nullptr);
    std::tm* tm_ptr = std::localtime(&now);
    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "%d.%m.%Y %H:%M:%S", tm_ptr);
    std::cout << "Formatierte Zeit: " << buffer << std::endl;

    // unix-timestamp zu utc zeit konventieren
    std::time_t t = 1721060000;  // Beispiel-Timestamp
    std::tm* utc = std::gmtime(&t);
    std::cout << "UTC-Zeit: " << std::asctime(utc);

    // Manuelle std::tm-Struktur → std::time_t (z. B. Datum berechnen)
    std::tm date = {};
    date.tm_year = 2025 - 1900;  // Jahre seit 1900
    date.tm_mon = 6;             // Juli (0-basiert)
    date.tm_mday = 15;
    std::time_t t2 = std::mktime(&date);
    std::cout << "Sekunden seit 1970: " << t2 << std::endl;

    
}