#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv) {
	PmergeMe	PmergeFJ;

	if (argc == 1)
		return 1;
	
	try {
		PmergeFJ.parse(argc, argv);
		PmergeFJ.run();
	} catch (const std::exception& e) {
		std::cerr <<  e.what() << std::endl;
		return(1);
	}

	return (0);
}

//./PmergeMe `jot 100000 1 | gshuf -n 3000 | tr "\n" " "`

//./PmergeMe `jot -r 3000 1 100000 | awk '!seen[$0]++' | tr "\n" " "`

//./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`