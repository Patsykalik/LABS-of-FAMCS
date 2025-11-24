#pragma once
#include <iostream>
class RightFraction{
public:
RightFraction()=delete;
RightFraction(int numerator,int denominator);
RightFraction(const RightFraction& other);
void reduce();
int getnumerator()const;
int getdenominator()const;
RightFraction sum(const RightFraction&other);
RightFraction difference(const RightFraction& other);
RightFraction product(const RightFraction&other);
RightFraction division(const RightFraction&other);
void print();

private:
int _numerator;
int _denominator;
};