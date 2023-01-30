#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

int main() {
    ifstream input_file("sample.txt");

    if (!input_file) {
        cerr << "Could not find file";
        return 1;
    }

    string line;
    size_t pos = 0;
    int counter = 0;
    int counter_pt2 = 0;
    string delimiter = ",";
    while(getline(input_file, line)) {
        pos = line.find(delimiter);
        string token = line.substr(0, line.find(delimiter));
        string token2 = line.substr(pos + 1, line.length());

        int pair1_1 = stoi(token.substr(0, token.find("-")));
        int pair1_2 = stoi(token.substr(token.find("-") + 1, token.length()));

        int pair2_1 = stoi(token2.substr(0, token2.find("-")));
        int pair2_2 = stoi(token2.substr(token2.find("-") + 1, token2.length()));

        if (pair2_1 >= pair1_1 && pair2_2 <= pair1_2) {
            counter++;
        }
        else if (pair1_1 >= pair2_1 && pair1_2 <= pair2_2) {
            counter++;
        }

        // Part two:
        if (pair1_1 <= pair2_1 && pair1_2 >= pair2_1) {
            counter_pt2++;
        }
        else if (pair2_1 <= pair1_1 && pair2_2 >= pair1_1) {
            counter_pt2++;
        }

    }
    cout << counter << endl;
    cout << counter_pt2 << endl;

    return counter;
}
