#include <iostream>
#include <list>
#include <string>

using namespace std;

class item {
    string _desc;
    int _value;
    public:
    item(const string &desc, int value) : _desc(desc), _value(value) {}

    const string &desc() const {return _desc;}

    int value() const {return _value;}
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}