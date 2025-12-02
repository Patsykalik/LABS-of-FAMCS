#include "lab73.h"
#include <bits/stdc++.h>
 
using namespace std;

Student_after2::Student_after2(const char* name, int course, string group, string transcript, int *marks, int *marks2)
:Student_after(name, course, group, transcript, marks){
    for (int i=0;i<5;i++){
        _marks2[i]=marks2[i];
    }
}
void Student_after2::avg_2() const{
    float sum=0;
    for (int i=0;i<4;i++){
        sum+=_marks[i];
    }
    for (int i=0;i<5;i++){
        sum+=_marks2[i];
    }
    cout<<sum/9<<'\n';
    return ; 
}
void Student_after2::check2(int i) const{
    if (i<1 || i>5){
        cout<<"Only 5 marks!\n";
        return;
    }
     cout<<_marks2[i-1]<<"\n";
}
void Student_after2::change2(int i, int d){
    if (i<=4 && i>=1){
        _marks[i-1]=d;
    }
    else if (i>=5 && i<=9){
        _marks2[i-5]=d;
    }
    else {
        cout<<"only 9 marks!!!\n";
        return;
    }
}
void Student_after2::print(std::ostream& os) const {
     Student_after::print(os);  
     os << "\nSecond session marks: ";
    for (int i = 0; i < 5; i++) {
        os << _marks2[i] << " ";
    }
    os << "\nYear average: " << average();
}
double Student_after2::group_average(Student_after2** students, int count, const string& group_name){
    double sums=0;
    int students_group=0;
    for (int i=0;i<count;i++){
        if (students[i]->getgroup() == group_name){
            sums+=students[i]->average();
            students_group++;
        }
    }
    if (students_group==0)return 0;
    else return sums/students_group;
}
double Student_after2::average() const {
    float sum=0;
    for (int i=0;i<4;i++){
        sum+=_marks[i];
    }
    for (int i=0;i<5;i++){
        sum+=_marks2[i];    
    }
    return sum/9;
}