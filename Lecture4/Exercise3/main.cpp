#include <iostream>
#include <list>

using namespace std;

void remdups(list<string> &ws) {
    if (ws.empty()) return;
    list<string>::iterator it = ws.begin();
    list<string>::iterator next = it;
    ++next;

    while (next != ws.end()) {
        if (*it == *next) {
            ws.erase(next);
        }
        else
            it = next;
            ++next;
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}