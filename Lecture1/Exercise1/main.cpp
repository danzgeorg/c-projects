#include <iostream>

/*
Write a program that requests the user’s age, reads the age they provide and then prints out:
"X is too young."
if the supplied age is less than 18,
"X is too old."
if the supplied age is greater than 30, and
"X is the right age."
otherwise, where in each case X is replaced by the supplied age.

*/

using namespace std;

int main() {
    cout << "What is your age? " << endl;
    int age;
    cin >> age;

    if (age <= 18) {
        cout << age << " is too young.";
    }

    else if (age >= 30) {
        cout << age << " is too old.";
    }

    else {
        cout << age << " is the right age.";
    }
}