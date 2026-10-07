#include <iostream>

/*
Write a program that requests the user’s name, reads the string they provide and then prints out:
Hello, XXXXXX!
==============
where XXXXXX is replaced by the name provided by the user.
Note: The number of equal signs in the bottom line should adjust to account for the length of
the name provided.
*/

int main() {
    std::cout << "What is your name? " << std::endl;
    std::string name;
    std::cin >> name;
    int size = int(name.size()) + 7;
    std::cout << "Hello, " << name << "!" << std::endl;
    for (int i = 0; i <= size; i++) {
        std::cout << "=";
    }

    return 0;

}