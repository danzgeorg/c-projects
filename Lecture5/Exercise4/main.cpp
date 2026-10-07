/*
Write a function that takes a list of ints and removes all the even numbers. Again, do this both
using an independent function and using a lambda expression.
*/

#include <iostream>
#include <list>

using namespace std;

int remove_even(list<int> &vs) {
    int count = 0;
    for (list<int>::iterator it = vs.begin(); it != vs.end(); ++it) {
        if (*it % 2 == 0) {
            vs.erase(it);
            count++;
        } else
            ++it;
    }
    return count;
}

int remove_even_lamba(list<int> &vs) {
    int before = vs.size();
    vs.remove_if([ ] (int &x) { return x % 2 == 0; });
    return before - vs.size();
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}