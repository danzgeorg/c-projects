/*
Write a function to count the number of negative numbers in a list of numbers. Do this both
using an independent function and using a lambda expression.
 */

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

bool is_negative(double x) {
    return x < 0;
}

int count_negatives(const list<double>& vs) {
    int count = 0;
    for (list<double>::const_iterator it = vs.begin(); it != vs.end(); ++it) {
        if (is_negative(*it)) {
            count++;
        }
    }
    return count;
}

int count_negatives_lambda(const list<double>& vs) {
    return count_if(vs.begin(), vs.end(), [](const double x ){ return x < 0; } );
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}