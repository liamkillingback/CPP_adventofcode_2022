#include <fstream>
#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include <regex>

#define max_stacks 100
using namespace std;

vector <string> createStacks(string filename); 
vector <string> get_instructions(string filename);
vector <string> rearrange(vector<string> vec, string instruction, int n);

int main(void) {
    
    vector <string> stacks = createStacks("sample.txt");
    vector <string> stacks2 = stacks;
    vector <string> instructions = get_instructions("sample.txt");
    vector <char> top_crates;
    vector <char> top_crates2 = top_crates;
   
    //Rearrange function takes an integer at the end to determine which part to execute ie. pt1 pt2, 1, 2
    for (size_t i = 0; i < instructions.size(); i++){
        stacks = rearrange(stacks, instructions[i], 1);
    }
    for (size_t i = 0; i < instructions.size(); i++){
        stacks2 = rearrange(stacks2, instructions[i], 2);
    }
    for (size_t i = 0; i < stacks.size(); i++){
        top_crates.push_back(stacks[i][stacks[i].length() - 1]);
        top_crates2.push_back(stacks2[i][stacks2[i].length() - 1]);

        
    }
    for(char x : top_crates){
        cout << x;
    }
    cout << endl;
    for(char x : top_crates2){
        cout << x;
    }
    cout << endl;

}

vector <string> createStacks(string filename) {
    //Opens file
    ifstream input_file(filename);
    //Checks wether the file exists
    if (!input_file) {
        cerr << "Could not find/open file";
        return vector<string>();
    }
    vector <char> stacks[max_stacks];
    vector <string> stacks_strings;

    //Reads lines until the empty line
    string line = "Initialize";
    while(getline(input_file, line) && !line.empty()) {
        for (int i = 0; i < line.length(); i++) {
            if (isalpha(line[i])) {
                stacks[i].push_back(line[i]);
            }
        }
    }
    //Iterates through the arrays, printing out the values of each, seperated by whitespace, 
    //and a new line for the next array/stack.
    string temp;
    for (size_t i = 1; i < max_stacks; i += 4) {
        for (auto it = stacks[i].rbegin(); it != stacks[i].rend(); it++){
            temp.push_back(*it);
            if(it + 1 == stacks[i].rend()){
                stacks_strings.push_back(temp);
                temp = "";
            }
        }
    }
    return stacks_strings;
}

vector <string> get_instructions(string filename) {
    ifstream input_file(filename);
    if(!input_file) {
        cerr << "Could not open file for instructions";
        return vector<string>();
    }
    string line;
    vector<string> instructions;
    //If line does not begin with m, it is not an instruction
    while(getline(input_file, line)) {
        if(line[0] == 'm') {
            instructions.push_back(line);
            
        }
    }
    return instructions;
}

vector <string> rearrange(vector<string> vec, string instruction, int n){
    vector<int> integers;
    regex pattern("\\d+");
    auto begin = sregex_iterator(instruction.begin(), instruction.end(), pattern);
    auto end = sregex_iterator();
    for (sregex_iterator i = begin; i != end; i++){
        string match = (*i).str();
        integers.push_back(stoi(match) - 1);
    }
    string origin = vec[integers[1]];
    string destination = vec[integers[2]];
    if (n == 1){
        for(int i = 0; i < integers[0] + 1; i++){
            destination.push_back(origin[origin.length() - 1]);
            origin.pop_back();
        }
    }
    else if (n == 2){
        for(int i = origin.length() - (integers[0] + 1); i < origin.length(); i++){
            destination.push_back(origin[i]);
        }
        for(int j = 0; j < integers[0] + 1; j++){
            origin.pop_back();
        }
    }
    vec[integers[1]] = origin;
    vec[integers[2]] = destination;
    return vec;
}
