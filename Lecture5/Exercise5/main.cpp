/*
Write a function
int count_longer(const vector<string> &v, int n)
that returns the number of strings in the vector that are longer than n.
*/

#include <iostream>
#include <vector>

using namespace std;

int count_longer(const vector<string> &v, int n) {
    return count_if(v.begin(), v.end(),
        [n](const string &s) { return s.size() > n; });
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}