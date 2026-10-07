#include <iostream>
#include <list>

using namespace std;

void delete_first_zero(list<double> &vs) {
    for (list<double>::iterator it = vs.begin(); it != vs.end(); ++it) {
        if (*it == 0.0) {
            vs.erase(it);
            return;
        }
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}