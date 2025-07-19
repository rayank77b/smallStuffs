#include <iostream>
#include <vector>
#include <numeric> // für std::accumulate, std::iota, std::inner_product, std::partial_sum

int main() {
    std::vector<int> values = {1, 2, 3, 4, 5};

    // 1. Summieren aller Werte
    int sum = std::accumulate(values.begin(), values.end(), 0);
    std::cout << "1) Summe: " << sum << "\n";

    // 2. Produkt aller Werte
    int product = std::accumulate(values.begin(), values.end(), 1, std::multiplies<int>());
    std::cout << "2) Produkt: " << product << "\n";

    // 3. Vektor auffüllen mit aufsteigenden Zahlen (iota)
    std::vector<int> numbers(10);
    std::iota(numbers.begin(), numbers.end(), 1); // füllt mit 1..10
    std::cout << "3) Iota: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << "\n";

    // 4. Skalarprodukt zweier Vektoren (inner_product)
    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = {4, 5, 6};
    int dot = std::inner_product(a.begin(), a.end(), b.begin(), 0);
    std::cout << "4) Skalarprodukt: " << dot << "\n";

    // 5. Partielle Summen (Teilsummen)
    std::vector<int> prefixSums(values.size());
    std::partial_sum(values.begin(), values.end(), prefixSums.begin());
    std::cout << "5) Partielle Summen: ";
    for (int x : prefixSums) std::cout << x << " ";
    std::cout << "\n";

    // 6. adjacent_difference
    std::vector<int> data = {10, 15, 25, 40};
    std::vector<int> diffs(data.size());

    std::adjacent_difference(data.begin(), data.end(), diffs.begin());

    std::cout << "6) adjacent_difference: ";
    for (int d : diffs) std::cout << d << " ";
    std::cout << "\n";

    // 7. adjacent_difference XOR
    std::vector<int> data2 = {10, 11, 15, 18};
    std::vector<int> diffs2(data.size());

    std::adjacent_difference(data2.begin(), data2.end(), diffs2.begin(), std::bit_xor<int>());
    
    std::cout << "7) adjacent_difference(xor): ";
    for (int d : diffs2) std::cout << d << " ";
    std::cout << "\n";

    std::vector<int> values2 = {1, 2, 3, 4};
    int xor_result = std::accumulate(values2.begin(), values2.end(), 0, std::bit_xor<int>());
    std::cout << "accumulate (XOR): " << xor_result << "\n";


    // string verkettung mit koma
    std::vector<std::string> words = {"Apfel", "Birne", "Zitrone"};
    std::string result = std::accumulate(
        words.begin() + 1, words.end(), words[0], // Start mit erstem Element
        [](const std::string& a, const std::string& b) {
            return a + "<->" + b;
        });
    std::cout << "accumulate (Strings): " << result << "\n";

    // T accumulate(InputIt first, InputIt last, T init, BinaryOp op);
}