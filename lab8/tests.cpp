#include <cassert>
#include <iostream>
#include "Stack.h"
#include "Calculator.h"


void testStack(){
    Stack<int> s;
    assert(s.empty());
    assert(s.size() == 0);
    s << 10;
    s << 20;
    assert(!s.empty());
    assert(s.size() == 2);
    assert(s[1] == 20);
    assert(s[0] == 10);

    int x;
    s >> x;
    assert(x == 20);
    assert(s.size() == 1);
    Stack<int> s2(s);
    assert(s2 == s);

    Stack<int> s3;
    s3 = s;
    assert(s3 == s);

    Stack<int> empty;
    bool thrown = false;
    try {
        empty >> x;
    } catch (...) {
        thrown = true;
    }
    assert(thrown);
}
void testCalculator() {
    Calculator c;
    assert(c.isValid("1+2"));
    assert(c.isValid("(1+2)*3"));
    assert(!c.isValid("1+"));
    assert(!c.isValid("(1+2"));

    // evaluate
    assert(c.evaluate("1+2") == 3);
    assert(c.evaluate("2*3") == 6);
    assert(c.evaluate("(1+2)*3") == 9);
    assert(c.evaluate("8/4") == 2);
}
int main() {
    testStack();
    testCalculator();
    std::cout<<"ALL is good\n";
    return 0;
}
