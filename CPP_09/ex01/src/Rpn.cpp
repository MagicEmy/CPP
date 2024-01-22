#include "Rpn.hpp"
#include <cctype>
#include <stdexcept>


std::stack<double> opStack;

void performOperation(char op) {

	double op1 = opStack.top();
	opStack.pop();
	
	switch (op)	{
	case '+': opStack.top() += op1; break;
	case '-': opStack.top() -= op1; break;
	case '*': opStack.top() *= op1; break;
	case '/': opStack.top() /= op1; break;
	}
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

double RPNCalculator::calculate(const std::string& expression) {

    for (size_t i = 0; i < expression.length(); ++i) {
        char c = expression[i];
        if (std::isdigit(c)) {
            int operand = c - '0';
            opStack.push(operand);
        } 
		else if (isOperator(c)) {
			if (opStack.size() < 2)
				throw std::runtime_error("Error: Invalid expression");
			performOperation(c);
        }
		else if (c != ' ')
            throw std::invalid_argument("Error: Invalid character found in the expression.");
	}
	if (opStack.size() != 1)
		throw std::runtime_error("Error: Invalid expression");
    return opStack.top();
}
