#ifndef MODULE_H
#define MODULE_H

#include <string>

// represents a module with code, credits, and name
class Module {
    std::string code;
    int credits;
    std::string name;

public:
    // constructor
    Module(const std::string& code, int credits, const std::string& name);

    // getters
    const std::string& get_code() const {
        return code;
    }

    int get_credits() const {
        return credits;
    }

    const std::string& get_name() const {
        return name;
    }
};

#endif