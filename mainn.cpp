#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::fstream inFile(argv[1]); // Open the input file
    if (!inFile.is_open()) {
        std::cerr << "Unable to open file " << argv[1];
        return 1;   // Return with error
    }
    std::vector<int> numbers;
    int number;
    while (inFile >> number) {
        numbers.push_back(number);
    }
    inFile.close();
    auto it = std::unique(numbers.begin(), numbers.end());
    size_t count_0 = std::count(numbers.begin(), it, 0);
    size_t count_1 = std::count(numbers.begin(), it, 1);

    std::ofstream outFile(argv[2]); // Open the output file
    if (!outFile.is_open()) {
        std::cerr << "Unable to open file " << argv[2];
        return 1;   // Return with error
    }

    outFile << count_1 << " " << count_0;
    outFile.close();

    return 0;
}
