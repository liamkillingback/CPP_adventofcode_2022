#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>
#include <string.h>
#include <unordered_map>

using namespace std;

int main(void) {
    //Open file and if file does not exist, exit with error message.
    ifstream input_file("data.txt");
    ifstream input_file2("data.txt");
    if(!input_file.is_open()) {
        cerr << "File not found" << endl;
        return 1;
    }
    //initialize variables and read through line by line
    int counter = 0;
    string rucksack;
    while(getline(input_file, rucksack)) {
        //split rucksack in half and compare both sides for same char.
        string first_half, second_half;
        int length = rucksack.length();
        first_half = rucksack.substr(0, (length / 2));
        second_half = rucksack.substr((length / 2), length);
        for (int i = 0; i < (length / 2); i++) {
            for (int j = 0; j < (length / 2); j++) {
                if (first_half[i] == second_half[j]) {
                    if (islower(first_half[i])) {
                        counter += (int)first_half[i] - 96;
                    }
                    else {
                        counter += (int)first_half[i] - 38;
                    }
                    goto loop;
                }
            }
        }
        loop:
        continue;
    }
    int counter2 = 0;
    string line;
    string line2;
    string line3;
    //imports 3 lines at a time
    for (int i = 0; i < 300; i+=3) {
        getline(input_file2, line);
        getline(input_file2, line2);
        getline(input_file2, line3);
        //Really O(n^3) time complexity (trash) way of finding the reoccuring letter
        for (int j = 0; j < line.length(); j++) {
            for (int k = 0; k < line2.length(); k++){
                for (int l = 0; l < line3.length(); l++){
                    if (line[j] == line2[k] && line2[k]== line3[l]){
                        if(islower(line[j])){
                            counter2 += (int)line[j] -96;
                        }
                        else {
                            counter2 += (int)line[j] -38;
                        }
                        goto marker;
                    }
                }
            }
        }
    marker:
    continue;
       

    }
    cout << "Part one: " << counter << endl;
    
    cout << "Part two: " << counter2 << endl;


    return 0;
}