# C++ projects

Lab exercises and coursework from C++ module.

## Coursework: student transcript generator

Reads modules and student grades from text files, then prints transcripts on request. Each transcript is grouped by term and sorted by module code, with a credit-weighted average per term and overall.

- `Module` and `Grade` classes, in separate header and source files
- File input with `ifstream` and `istringstream`
- STL containers (`map`, `vector`) and algorithms (`sort`)

```bash
cd Coursework
g++ -std=c++17 main.cpp module.cpp grade.cpp -o transcripts
./transcripts
```

## Lab exercises

`Lecture1` to `Lecture6` hold the weekly exercises: input and output, vectors, string parsing and more.
