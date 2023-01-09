#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

int main() {
    // Open the file for reading
    std::ifstream input_file("big.txt");

    // Make sure the file was opened successfully
    if (!input_file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::vector<int> sums;

    // Read the numbers from the file and calculate the sums
    std::string line;
    int sum = 0;
    while (std::getline(input_file, line)) {
        if (line.find_first_not_of(' ') == std::string::npos) {
        // The line is empty or contains only whitespace, so store the current sum and reset it
        sums.push_back(sum);
        sum = 0;
        } else {
        // The line contains a number, so add it to the current sum
        std::istringstream value(line);
        int num;
        value >> num;
        sum += num;
        }
    }
    // Store the final sum
    sums.push_back(sum);
    // Close the file
    input_file.close();

    int most_calories = 0;
    int second_most = 0;
    int third_most = 0;

    for (std::size_t i = 0; i < sums.size(); i++) {
        if (sums[i] > most_calories) {
            third_most = second_most;
            second_most = most_calories;
        }
        most_calories = std::max(most_calories, sums[i]);
    }

    int total = most_calories + second_most + third_most;

    std::cout << "Maximum value: " << most_calories << std::endl;
    std::cout << "Total value:" << total << std::endl;

    return total;
}