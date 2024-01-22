#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <list>


int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	std::cout << "pushed 5" << std::endl;
	mstack.push(17);
	std::cout << "pushed 17" << std::endl;
    std::cout << "mstack top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "popped" << std::endl;
	std::cout << "mstack size: " << mstack.size() << std::endl;
	mstack.push(3);
	std::cout << "pushed 3" << std::endl;
	mstack.push(5);
	std::cout << "pushed 5" << std::endl;
	mstack.push(737);
	std::cout << "pushed 737" << std::endl;
	//[...]
	mstack.push(0);
	std::cout << "pushed 0" << std::endl;
	std::cout << "mstack size: iteration" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	// std::stack<int> s(mstack);
	{	// Testing copy constructor and =operator
			MutantStack<int> mySecondStack(mstack);
			MutantStack<int> myThirdStack = mstack;
			std::stack<int> myFourthStack(mstack);
			std::stack<int> myFifthStack = mstack;
			
	}
	{	// Testing empty stack	
		MutantStack<int> mySecondStack;
		std::stack<int> myFourthStack;
		std::cout << "mySecondStack.empty(): " << mySecondStack.empty() << std::endl;
		std::cout << "myFourthStack.empty(): " << myFourthStack.empty() << std::endl;
	}
	{	// Testing top
		MutantStack<int> mySecondStack(mstack);
		std::stack<int> myFourthStack(mstack);
		std::cout << "mySecondStack.top(): " << mySecondStack.top() << std::endl;
		std::cout << "myFourthStack.top(): " << myFourthStack.top() << std::endl;
	}
	{	// Testing pop
		MutantStack<int> mySecondStack(mstack);
		std::stack<int> myFourthStack(mstack);
		mySecondStack.pop();
		myFourthStack.pop();
		std::cout << "mySecondStack.top(): " << mySecondStack.top() << std::endl;
		std::cout << "myFourthStack.top(): " << myFourthStack.top() << std::endl;

		std::cout << "\nmymstack empty?  " << mstack.empty() << std::endl;
		mstack.clear();
		std::cout << "mstack.clear() called " <<  std::endl;
		std::cout << "mymstack empty? " << mstack.empty() << std::endl;
	}
{		
		std::cout << "\ncomparing MutantStack<T> to std::list" << std::endl;

		std::list<int> mlist;

		mlist.push_front(5);
		mstack.push(5);
		mlist.push_front(17);
		mstack.push(17);

		std::cout << "mlist.front() " << mlist.front() << "\t";
		std::cout << "mstack.top() " << mstack.top() << std::endl;

		mlist.pop_front();
		mstack.pop();

		std::cout << "mlist.size() " << mlist.size() << "\t\t";
		std::cout << "mstack size() " << mstack.size() << std::endl;

		mlist.push_front(3); mlist.push_front(5); mlist.push_front(737);
		mstack.push(3); mstack.push(5);	mstack.push(737);

		std::list<int>::iterator it = mlist.begin(); std::list<int>::iterator ite = mlist.end();
		++it;
		--it;

		while (it != ite) {
			std::cout <<  "mlist: " << *it << std::endl;
			++it;
		}

		MutantStack<int>::reverse_iterator rbeg = mstack.rbegin();
		MutantStack<int>::reverse_iterator rend = mstack.rend();
		while (rbeg != rend)
		{
			std::cout << "mstack: " << *rbeg << std::endl;
			++rbeg;
		}
		std::stack<int, std::list<int> > s(mlist);
	}
	return 0;
}