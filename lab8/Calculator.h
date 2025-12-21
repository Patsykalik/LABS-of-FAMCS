#pragma once
#include <string>
#include <cctype>
#include <stdexcept>
#include "Stack.h"

class Calculator {
public:
    bool isValid(const std::string& expr) const {
        Stack<char> stack;
        bool lastWasOp = true;

        for (char c : expr) {
            if (c == '(') {
                stack << c;
                lastWasOp = true;
            } else if (c == ')') {
                if (stack.empty()) return false;
                char t; stack >> t;
                lastWasOp = false;
            } else if (std::isdigit(c)) {
                lastWasOp = false;
            } else if (isOperator(c)) {
                if (lastWasOp) return false;
                lastWasOp = true;
            }
        }
        return stack.empty() && !lastWasOp;
    }

    double evaluate(const std::string& expr) {
    Stack<double> values;
    Stack<char> ops;

    for (int i = 0; i < expr.size(); ++i) {
        char c = expr[i];
        if (std::isdigit(c)) {
            double number = 0;

            while (i < expr.size() && std::isdigit(expr[i])) {
                number = number * 10 + (expr[i] - '0');
                ++i;
            }
            values << number;
            --i; 
        }
        else if (c == '(') {
            ops << c;
        }
        else if (c == ')') {
            while (!ops.empty() && ops[ops.size() - 1] != '(')
                applyOp(values, ops);

            char tmp;
            ops >> tmp; 
        }
        else if (isOperator(c)) {
            while (!ops.empty() &&
                   priority(ops[ops.size() - 1]) >= priority(c))
                applyOp(values, ops);

            ops << c;
        }
    }

    while (!ops.empty())
        applyOp(values, ops);

    double result;
    values >> result;
    return result;
}

private:
    bool isOperator(char c) const {
        return c=='+'||c=='-'||c=='*'||c=='/';
    }
    int priority(char c) const {
        if (c=='+'||c=='-') return 1;
        if (c=='*'||c=='/') return 2;
        return 0;
        }
    void applyOp(Stack<double>& v, Stack<char>& o) {
        double b,a; char op;
        v>>b; v>>a; o>>op;
        if(op=='+') v<<(a+b);
        if(op=='-') v<<(a-b);
        if(op=='*') v<<(a*b);
        if(op=='/') v<<(a/b);
    }
};