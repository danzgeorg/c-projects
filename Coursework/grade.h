#ifndef COURSEWORK_GRADE_H
#define COURSEWORK_GRADE_H

#include <string>

// represents a student's grade for a specific module in a specific term
class Grade {
    std::string student_id;
    int term;
    std::string module_code;
    int mark;

public:
    // constructor
    Grade(const std::string& student_id, int term,
          const std::string& module_code, int mark);

    // getters
    const std::string& get_student_id() const {
        return student_id;
    }

    int get_term() const {
        return term;
    }

    const std::string& get_module_code() const {
        return module_code;
    }

    int get_mark() const {
        return mark;
    }
};

#endif