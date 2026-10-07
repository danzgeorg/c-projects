#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    cout << "Please enter a series of numbers: " << endl;

    // store into vector then store all values into it
    vector<int> numbers;
    int x;
    while (cin >> x) {
        numbers.push_back(x);
    }
    auto n = numbers.size(); // size of the vector

    if (n > 2 ) { // has to be 3 or more to remove min/max
        sort(numbers.begin(), numbers.end());
        double sum = 0.0;
        for (unsigned i = 1; i < n - 1; i++) { // start at index 1, and finish at index n-1, checking i pos before increment
            sum += numbers[i];
        }

        double average = sum / (n-2); // (n-2) to account for not including min/max
        cout << setprecision(3) << "average without min/max = " << average << endl;

    }


    return 0;
}