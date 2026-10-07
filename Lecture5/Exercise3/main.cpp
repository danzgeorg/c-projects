/*
 Write a function to split a string containing comma-separated values into a vector of strings. For
 example, the string "abc,,d,ef," should yield a vector of 5 elements, "abc", "", "d",
 "ef" and "".
*/

#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<string> split_csv(const string &s) {
    vector<string> result;
    string current;

    for (string::size_type i = 0; i < s.size(); ++i) {
        if (s[i] == ',') {
            result.push_back(current);  // value before comma
            current.clear();            // start new value
        } else {
            current += s[i];
        }
    }
    result.push_back(current);
    return result;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}