#pragma once
#include "lab71.h"
#include <iostream>

class Student_after : public Student {
public:
    Student_after(const char* name, int course, std::string group, std::string transcript, int* marks); 
    
    void check(int i) const;
    void change(int i, int d);
    
    double average() const override;
    static double group_average(Student_after** students, int count, 
                                const std::string& group);
    void print(std::ostream& os) const override;
    
protected:
    int _marks[4];
};