#include "grade.h"

using namespace std;

// constructor implementation
Grade::Grade(const string& student_id, int term,
             const string& module_code, int mark)
    : student_id(student_id), term(term), module_code(module_code), mark(mark) {
}