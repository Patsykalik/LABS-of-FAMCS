
#include "Fractions.h"
#include <bits/stdc++.h>

RightFraction::RightFraction(int numerator, int denominator){
    _numerator=numerator;
    _denominator=denominator;
    reduce();
}
RightFraction::RightFraction(const RightFraction& other){
_numerator=other._numerator;
_denominator=other._denominator;
}   
void RightFraction::reduce() {
    int gcd1=std::gcd(_numerator,_denominator);
 _numerator/=gcd1; 
 _denominator/=gcd1;
}
 int RightFraction::getnumerator()const{
    return _numerator;
}
int RightFraction::getdenominator()const{
    return _denominator;
}
RightFraction RightFraction::sum(const RightFraction& other){
    int denominator3 = _denominator * other._denominator;
    int numerator3 = (_numerator * other._denominator) + (other._numerator * _denominator);
    return RightFraction(numerator3, denominator3);
}
 RightFraction RightFraction::difference(const RightFraction& other){
    int denominator3 = _denominator*other._denominator;
    int numerator3 = _numerator*other._denominator-other._numerator*_denominator;
    
     return RightFraction(numerator3, denominator3);
}
RightFraction RightFraction::product(const RightFraction&other){
    int denominator3=_denominator*other._denominator;
    int numerator3=_numerator*other._numerator;
    reduce();
     return RightFraction(numerator3,denominator3);
}
RightFraction RightFraction::division(const RightFraction&other){
    int denominator3=_denominator*other._numerator;
    int numerator3=_numerator*other._denominator;
    reduce();
     return RightFraction(numerator3,denominator3);
}
void RightFraction::print(){
    // std::cout  << "govnoxuypenischlenzalupa\n";
    if ((_numerator>=0 and _denominator>=0) or (_numerator<=0 and _denominator<=0))
        std::cout<<abs(_numerator)<<'/'<<abs(_denominator) << "\n";
    else std::cout<<-abs(_numerator)<<'/'<<abs(_denominator) << "\n";
}


