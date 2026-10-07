#include <iostream>
#include <list>

using namespace std;

/* Write a function
void scale(double s, list<double> &vs)
that modifies vs, multiplying each element by s. Again, do this both as an iterator loop and as
a ranged for loop. (This will need iterator rather than const_iterator.)

*/


void scale(double s, list<double> &vs) {
    for (list<double>::iterator it = vs.begin(); it != vs.end(); it++) {
        (*it) *= s;
    }
}

void scale2(double s, list<double> &vs) {
    for (double & v : vs) {
        v *= s;
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}