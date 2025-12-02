#include "lab73.h"
#include <bits/stdc++.h>

void palochki(){
  std::cout<<"\n--------------------------------\n\n";
 }

int main(){
    int marks1[4] = {5, 4, 3, 5};
    int marks11[4]={1, 1, 1, 3}; 
    int marks2[5] = {4, 5, 4, 3, 5};
    const int array_size=4;
    Student* students[array_size];
    students[0]=new Student_after("Patsykalik Andrey", 1, "4","1000001", marks1);
    students[1]=new Student_after("Vyacheslave", 1, "4","1000002", marks11);
    students[2]=new Student_after2("yatoro", 2,"1488","1000003",marks1,marks2);
    students[3]=new Student_after2("Miracle", 2,"1488","1000004",marks11,marks2);

    for (int i=0;i<array_size;i++){
        std::cout<<*students[i];
        palochki();
    }
        double total_sum = 0;
    
    std::cout << "average mark of students:\n";
    for (int i = 0; i<array_size; i++) {
        double avg = students[i]->average();
        total_sum += avg;
        std::cout << i+1 << ". "<<students[i]->getname() 
                  << " (группа "<<students[i]->getgroup() << "): "
                  << std::fixed << std::setprecision(2) << avg << std::endl;
    }
    
    double overall_average = total_sum /array_size;
    
   palochki();
    std::cout << "total students: " << array_size << std::endl;
    std::cout << "average mark of array: " 
              << std::fixed << std::setprecision(3) << overall_average << std::endl;
    
    for (int i = 0; i < array_size; i++) {
        delete students[i];
    }
    
    return 0;
}
