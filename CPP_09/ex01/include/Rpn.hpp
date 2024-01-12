#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>

namespace RPNCalculator {

		std::stack<double> _opStack; //default constructor of std::stack creates an empty container

		bool performOperation(char op);

	// public:

	// 	RPNCalculator();
	//     ~RPNCalculator();
	// 	RPNCalculator(const RPNCalculator& other);
	// 	RPNCalculator& operator=(const RPNCalculator& other);

   		double calculate(const std::string& expression);
};

#endif // RPN_HPP