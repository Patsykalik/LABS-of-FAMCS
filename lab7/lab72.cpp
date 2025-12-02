#include "lab72.h"
#include <bits/stdc++.h>

using namespace std;


    Student_after::Student_after(const char *name, int course, string group, string transcript, int *marks) : Student(name, course, group, transcript){
        for (int i = 0; i < 4; i++){
            _marks[i] = marks[i];
        }
    }
 
   
    void Student_after::check(int i) const{
    if (i<1 || i>4){
        cout<<"Only 4 marks!\n";
        return;
    }
     cout<<_marks[i-1]<<"\n";
}
    

    void Student_after::change(int i, int d){
       if (i<1 or i>4){
            cout<<"only 4 marks!!!\n";
            return;
        }
        _marks[i-1]=d;
        cout<<"Mark "<<i<<"is "<<_marks[i-1]<<'\n';
        return;
    }
    double Student_after::group_average(Student_after** students, int count, const string& group){
        double sum=0;
        int student_count=0;
        for (int i=0;i< count; i++){
            if (students[i]->getgroup()==group){
                sum+=students[i]->average();
                student_count++;
            }
        }
        if (student_count==0){
            return 0;
        }
        else return sum/student_count;
    }
    void Student_after::print(std::ostream& os) const {
     Student::print(os);
        os<<"\nFirst session marks: ";
    for (int i=0;i<4;i++) {
        os<<_marks[i]<<" ";
    }
    os<<"\nAverage after first session: "<<average();
}
double Student_after::average() const {
    float sum=0;
    for (int i=0;i < 4 ;i++){
        sum+=_marks[i];
    }
    return sum / 4;
}