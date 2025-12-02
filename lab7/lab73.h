    #pragma once
    #include "lab72.h"
    #include <bits/stdc++.h>

    class Student_after2 : public Student_after{
    public:
    Student_after2(const char* name, int course, std::string group, std::string transcript, int *marks, int *marks2);
    void avg_2() const;
    void change2(int i, int d);
    void check2(int i) const;
    double average() const override;
    static double group_average(Student_after2** students, int count, const std::string& group);
    void print(std::ostream& os) const override; 
    private:
    int _marks2[5];

    };