#include <iostream>
#include <vector>
#include <numeric>

struct Person {
    std::string name;
    int age;
    double weight;
};

struct Stats {
    int totalAge = 0;
    double totalWeight = 0.0;
};

int main() {
    std::vector<Person> people = {
        {"Anna", 25, 60.5},
        {"Bob", 30, 80.2},
        {"Cara", 22, 55.8}
    };

    double totalWeight = std::accumulate(
        people.begin(), people.end(), 0.0,
        [](double sum, const Person& p) {
            return sum + p.weight;
        });

    std::cout << "Gesamtgewicht: " << totalWeight << " kg\n";
    

    double sumAge = std::accumulate(
    people.begin(), people.end(), 0,
    [](int sum, const Person& p) {
        return sum + p.age;
    });
    double avgAge = sumAge / static_cast<double>(people.size());

    std::cout << "Alter gesamt: " << sumAge << "\n";
    std::cout << "Durchschnittsalter: " << avgAge << " Jahre\n";


    Stats result = std::accumulate(
    people.begin(), people.end(), Stats{},
    [](Stats acc, const Person& p) {
        acc.totalAge += p.age;
        acc.totalWeight += p.weight;
        return acc;
    });

    std::cout << "Alter gesamt: " << result.totalAge << "\n";
    std::cout << "Gewicht gesamt: " << result.totalWeight << " kg\n";
}