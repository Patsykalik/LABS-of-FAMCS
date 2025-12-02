#pragma once
#include <iostream>
#include <string>


class Student{

 public:
Student()=delete;
 Student(const char* name, int course, std::string group, std::string transcript);
Student(const Student& other);

    virtual ~Student();
    char* getname()const;
    int getcourse() const;
    std::string getgroup() const;
    int getcode() const;
    std::string gettranscript() const;

    void  setname(const char* &name1);
    void  setcourse(int course1);
    void  setgroup(const std::string &group1);

    virtual double average() const=0;
    friend std::ostream& operator<<(std::ostream& os, const Student& st);
    virtual void print(std::ostream& os) const;

private:
int _code;
static int next;
char* _name;
int _course;
std::string _group;
const std::string _transcript;
};


