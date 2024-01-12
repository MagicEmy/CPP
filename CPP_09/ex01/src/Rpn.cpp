#include "Rpn.hpp"
#include <cctype>
#include <stdexcept>

// RPNCalculator::RPNCalculator() {}

// RPNCalculator::~RPNCalculator() {}

// RPNCalculator::RPNCalculator(const RPNCalculator& other) {
// 	*this = other;
// }

// RPNCalculator& RPNCalculator::operator=(const RPNCalculator& other) {
// 	if (this != &other) {
// 		_opStack = other._opStack;
// 	}
// 	return *this;
// }

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

double RPNCalculator::calculate(const std::string& expression) {

    for (size_t i = 0; i < expression.length(); ++i) {
        char c = expression[i];
        if (std::isdigit(c)) {
            int operand = c - '0';
            _opStack.push(operand);
        } 
		else if (isOperator(c)) {
			if (_opStack.size() > 2)
				throw std::runtime_error("Error: Invalid expression");
			else {
				if (!performOperation(c)){
					throw std::runtime_error("Error: Invalid expression");
				}
			}
        }
		else if (c != ' ')
            throw std::invalid_argument("Error: Invalid character found in the expression.");
	}
	if (_opStack.size() != 1)
		throw std::runtime_error("Error: Invalid expression");
    return _opStack.top();
}


bool RPNCalculator::performOperation(char op) {

	double op1 = _opStack.top();
	_opStack.pop();
	
	switch (op)	{
	case '+': _opStack.top() += op1; break;
	case '-': _opStack.top() -= op1; break;
	case '*': _opStack.top() *= op1; break;
	case '/': _opStack.top() /= op1;; break;
	}
	return true;
}
