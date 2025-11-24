#include "Fractions.h"
#include <bits/stdc++.h>

using namespace std;
 void palochki(){
  cout<<"\n----------\n\n";
 }
int main() {
    RightFraction FR(5, 3);
    RightFraction FR_copy = RightFraction(FR);
    FR_copy.print();

    palochki();
    RightFraction FR1(-5, 10); 
    RightFraction FR2(5, -10); 
    RightFraction FR3(-1, -4);
    FR1.print(), FR2.print(), FR3.print();
    
    palochki();
    FR = FR.product(FR1);
    FR.print();
    FR = RightFraction(FR_copy);

    FR = FR.division(FR2);
    FR.print();
    FR = RightFraction(FR_copy);

    FR = FR.sum(FR3);
    FR.print();
    FR = RightFraction(FR_copy);
    return 0;
}
