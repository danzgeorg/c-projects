#include "module.h"
#include "grade.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

// read modules from file into a map
map<string, Module> read_modules(const string& filename) {
    map<string, Module> modules;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        istringstream iss(line);
        string code, name;
        int credits;

        iss >> code >> credits >> name;
        modules.insert({code, Module(code, credits, name)});
    }
    return modules;
}

// read grades from file into a vector
vector<Grade> read_grades(const string& filename) {
    vector<Grade> grades;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        istringstream iss(line);
        string student_id, module_code;
        int term, mark;

        iss >> student_id >> term >> module_code >> mark;
        grades.push_back(Grade(student_id, term, module_code, mark));
    }
    return grades;
}

// calculate credit-weighted average for a list of grades
double calculate_average(const vector<Grade>& grades,
                         const map<string, Module>& modules) {
    double total_weighted_marks = 0.0;
    int total_credits = 0;

    for (const auto& grade : grades) {
        const Module& module = modules.at(grade.get_module_code());
        total_weighted_marks += grade.get_mark() * module.get_credits();
        total_credits += module.get_credits();
    }

    if (total_credits == 0) {
        return 0.0;
    }

    return total_weighted_marks / total_credits;
}

// print transcript for a student
void print_transcript(const string& student_id, int requested_term,
                      const vector<Grade>& all_grades,
                      const map<string, Module>& modules) {
    cout << "Student ID: " << student_id << '\n';

    // filter grades for this student
    vector<Grade> student_grades;
    for (const auto& grade : all_grades) {
        if (grade.get_student_id() == student_id) {
            if (requested_term == -1 || grade.get_term() == requested_term) {
                student_grades.push_back(grade);
            }
        }
    }

    // group grades by term
    map<int, vector<Grade>> grades_by_term;
    for (const auto& grade : student_grades) {
        grades_by_term[grade.get_term()].push_back(grade);
    }

    // print each term
    for (auto& term_pair : grades_by_term) {
        int term = term_pair.first;
        vector<Grade>& term_grades = term_pair.second;

        // sort grades by module code
        sort(term_grades.begin(), term_grades.end(),
             [](const Grade& a, const Grade& b) {
                 return a.get_module_code() < b.get_module_code();
             });

        cout << "  Term " << term << ":\n";

        // print each module
        for (const auto& grade : term_grades) {
            const Module& module = modules.at(grade.get_module_code());
            cout << "    " << module.get_code() << " " << module.get_name()
                 << " (" << module.get_credits() << " credits): "
                 << grade.get_mark() << '\n';
        }

        // calculate and print term average
        double avg = calculate_average(term_grades, modules);
        cout << "  Term Average: " << fixed << setprecision(2) << avg << '\n';
    }

    // print overall average if showing multiple terms
    if (requested_term == -1 && grades_by_term.size() > 1) {
        double overall_avg = calculate_average(student_grades, modules);
        cout << "  Overall Average: " << fixed << setprecision(2)
             << overall_avg << '\n';
    }

    cout << '\n';
}

// process requests file
void process_requests(const string& filename,
                      const vector<Grade>& grades,
                      const map<string, Module>& modules) {
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        istringstream iss(line);
        string student_id;
        int term = -1;

        iss >> student_id;
        if (iss >> term) {
            // term specified
            print_transcript(student_id, term, grades, modules);
        } else {
            // full transcript
            print_transcript(student_id, -1, grades, modules);
        }
    }
}

int main() {
    // read data files
    map<string, Module> modules = read_modules("modules.txt");
    vector<Grade> grades = read_grades("grades.txt");

    // process requests
    process_requests("requests.txt", grades, modules);

    return 0;
}