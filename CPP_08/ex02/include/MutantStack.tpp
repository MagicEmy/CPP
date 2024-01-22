
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() {
	return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const {
	return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() {
	return this->c.rend();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const {
	return this->c.rend();
}

template <typename T>
void MutantStack<T>::clear() {
	this->c.clear();
}


/*
The c member is a protected member of the std::stack class template 
which MutantStack is inheriting from.
In the context of std::stack, c is the underlying container object. 
The std::stack is a container adapter, meaning it’s implemented on top
of some underlying container type. 
By default, this is std::deque, but it could be any other type that 
satisfies the container requirements.

The c member is protected, which means it can be accessed directly 
within std::stack and within classes that inherit from std::stack, 
However, it’s important to note that directly accessing c breaks 
the encapsulation of the std::stack and may lead to unexpected behavior.
*/