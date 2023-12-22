

template <typename T>
Array<T>::Array(void) : _aSize(0), _arr(nullptr) {}

template <typename T>
Array<T>::Array(size_t n) : _aSize(n), _arr(new T[_aSize]) {}

template <typename T>
Array<T>::Array(const Array &src) : _aSize(src._aSize), _arr(new T[_aSize]) {

	*this = src;
}

template <typename T>
Array<T>::~Array(){
	delete [] _arr;
}

template <typename T>
Array<T> &Array<T>::operator =(const Array &src){

	if (this == &src)
		return *this;
	delete [] _arr;
	this->_aSize = src._aSize;
	this->_arr = new T[_aSize];
	for (size_t i = 0; i < _aSize; ++i){
		this->_arr[i] = src._arr[i];
	}
	return *this;
}

template <typename T>
T &Array<T>::operator [](const unsigned int index){

	if (index >= _aSize)
		throw OutOfBounds();
	return _arr[index];
}

template <typename T>
size_t Array<T>::size( void ) const {

	return _aSize;
}