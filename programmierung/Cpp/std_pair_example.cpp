#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

int main() {

    std::vector<std::pair<std::string,int>> data = {
        {"John", 28},
        {"Blub", 18},
        {"Deer", 34}
    };
    std::pair<std::string,int> mypair;

    data.push_back({"oppala",23});

    std::string myinput;
    std::cout<<"input: ";
    std::cin>>myinput;

    mypair.first=myinput;
    mypair.second=20330;

    data.push_back({myinput,23});

    data.push_back(mypair);

    std::sort(data.begin(), data.end(), [](const auto& a, const auto& b){
        return a.second  < b.second;
    });

    for (const auto& pair : data) {
        std::cout<< pair.first << ": "<< pair.second << std::endl;
    }

    return 0;
}