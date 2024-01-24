#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <chrono>
#include <string>

class PmergeMe
{
	private:
			std::vector<int>	_sequence;
			std::deque<int>		_deSequence;
			std::vector<int>	_jacobsthalNumbers;

			void generateJacobsthalNumbers();
			bool inputValidation(int argc, char **argv);
			void mergeInsert(const std::vector<int>& input, std::vector<int>& sorted, std::vector<int>& toSort);
			void splitAndSortVect(const std::vector<int>& vectInput, std::vector<int>& sorted, std::vector<int>& toSort );
			void mergeInsertDeque(const std::deque<int>& input, std::deque<int>& sorted, std::deque<int>& toSort);
			void splitAndSortDeque(const std::deque<int>& dequeInput, std::deque<int>& sorted, std::deque<int>& toSort );
			void displayTimeVec(const std::string& containerType, const std::chrono::microseconds& duration);
			void displayTimeDeq(const std::string& containerType, const std::chrono::microseconds& duration);
			
	public:
			PmergeMe();
			~PmergeMe();
			PmergeMe(const PmergeMe &src);
			PmergeMe &operator=(const PmergeMe &src);

			void parse(int argc, char **argv);
			void run( void );
};

#endif // PMERGEME_HPP



