#include <fstream>
#include <iostream>
#include <sstream>


int main() {
    std::ifstream input_file("games.txt");
    std::ifstream part_two_file("games.txt");

    if (!input_file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }
    int my_score, part_two_score = 0;
    std::string line;

    while (std::getline(input_file, line)) {

        if (line == "A X") {
            my_score += 4;
        }
        else if(line == "A Y") {
            my_score += 8;
        }
        else if(line == "A Z") {
            my_score += 3;
        }
        else if(line == "B X") {
            my_score += 1;
        }
        else if(line == "B Y") {
            my_score += 5;
        }
        else if(line == "B Z") {
            my_score += 9;
        }
        else if(line == "C X") {
            my_score += 7;
        }
        else if(line == "C Y") {
            my_score += 2;
        }
        else if(line == "C Z") {
            my_score += 6;
        }
    }
    std::cout << my_score << std::endl;

    //part 2
    while(std::getline(part_two_file, line)) {
        if (line == "A X") {
            part_two_score += 3;
        }
        else if(line == "A Y") {
            part_two_score += 4;
        }
        else if(line == "A Z") {
            part_two_score += 8;
        }
        else if(line == "B X") {
            part_two_score += 1;
        }
        else if(line == "B Y") {
            part_two_score += 5;
        }
        else if(line == "B Z") {
            part_two_score += 9;
        }
        else if(line == "C X") {
            part_two_score += 2;
        }
        else if(line == "C Y") {
            part_two_score += 6;
        }
        else if(line == "C Z") {
            part_two_score += 7;
        }
    }
    std::cout << part_two_score << std::endl;
}