/*
 Write a function than takes a list of numbers, and returns the number of zeroes that occur before
 the first 1 in the list.
*/

#include <iostream>
#include <list>

using namespace std;

int number_zeroes(list<double> &vs) {
    int count = 0;

    for (list<double>::iterator it = vs.begin(); it != vs.end(); ++it) {
        if (*it == 1) {
            break;
        }
        if (*it == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}