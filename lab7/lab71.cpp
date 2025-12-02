#include "lab71.h"
#include <bits/stdc++.h>

using namespace std;
int Student::next=1;
Student::Student(const char* name, int course, string group, string transcript)
    : _course(course), _group(group), _transcript(transcript), _code(next++){
    _name = new char[strlen(name) + 1];
    strcpy(_name, name);
}
Student::Student(const Student& other)
    : _course(other._course),
      _group(other._group),
      _transcript(other._transcript),
      _code(next++){
    _name = new char[strlen(other._name) + 1];
    strcpy(_name, other._name);
}

Student::~Student(){
    delete[] _name;
}
char* Student::getname()const{
    return _name;
}
int Student::getcourse() const{
    return _course;
}
string Student::getgroup() const{
    return _group;
}
int Student::getcode () const{
    return _code;
}
string Student::gettranscript()const{
    return _transcript;
}
void  Student::setname(const char* &name1){
    delete[] _name;
    _name = new char[strlen(name1)+1];
    strcpy(_name,name1);
}
void Student::setcourse(int course1){
    _course=course1;
}
void  Student::setgroup(const string& group1){
    _group=group1;
}
void Student::print(std::ostream& os) const {
    os <<"ID: "<< _code 
       <<", Name: "<< _name 
       <<", Course: "<< _course 
       <<", Group: "<< _group 
       <<", Transcript: "<< _transcript;
}
ostream& operator<<(std::ostream& os, const Student& st) {
    st.print(os);
    return os;
}




