#include "Rpn.hpp"
#include "iostream"

int main( int argc, char **argv) {

	if (argc != 2) {

		std::cerr << "Usage: " << argv[0] 
		<< " <inverted Polish mathematical expression>"
		<< std::endl;
		return 0;
	}

	try {

		double result = RPNCalculator::calculate(argv [1]);
		std::cout << result << std::endl;
	}
	catch(const std::exception& e) {

		std::cerr << e.what() << '\n';
	}

}

//https://paodayag.dev/reverse-polish-notation-js-parser/