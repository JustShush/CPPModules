#ifndef ARRAY_H
# define ARRAY_H

# include "./header.hpp"

# include <iostream>

template <typename T>
class Array
{
private:
	T* arr;
	unsigned int _n;
public:
	/* ++ Orthodox Canonical Form ++ */
	Array();
	Array(const Array<T> &copy);
	Array<T>& operator=(const Array<T> &copy_a);
	~Array();
	/* ++ Orthodox Canonical Form ++ */

	Array(unsigned int n);

	void Print(void);

	int size(void);

	/* -+-+-+-+-+-+-+-+- Operators -+-+-+-+-+-+-+-+- */
	T& operator[](unsigned int elem);
	/* -+-+-+-+-+-+-+-+- Operators -+-+-+-+-+-+-+-+- */

	/* /-/-/-/-/-/-/-/-/ Exceptions /-/-/-/-/-/-/-/-/ */
	class OutOfBounds : public std::exception {
	public:
		virtual const char	*what() const throw();
	};
	/* /-/-/-/-/-/-/-/-/ Exceptions /-/-/-/-/-/-/-/-/ */

};

/* ++++++++++ Orthodox Canonical Form ++++++++++ */
template <typename T> Array<T>::Array() {
	arr = new T[0];
	_n = 0;
	std::cout << GREEN << "Array Default Constructor Called" << RESET << std::endl;
}

template <typename T> Array<T>::Array(const Array<T> &copy) {
	std::cout << GREEN << "Array Copy Constructor Called" << RESET << std::endl;
	arr = NULL;
	*this = copy;
}

template <typename T> Array<T>& Array<T>::operator=(const Array<T> &copy_a) {
	if (arr)
		delete[] arr;
	_n = copy_a._n;
	arr = new T[_n];
	for (unsigned int i = 0; i < _n; i++)
		arr[i] = copy_a.arr[i];
	std::cout << GREEN << "Array Copy Assignment Operator Called" << RESET << std::endl;
	return (*this);
}

template <typename T> Array<T>::~Array() {
	delete[] arr;
	std::cout << RED << "Array Destructor Called" << RESET << std::endl;
}
/* ++++++++++ Orthodox Canonical Form ++++++++++ */

template <typename T> Array<T>::Array(unsigned int n) {
	arr = new T[n];
	_n = n;
	std::cout << GREEN << "Array Size Constructor Called" << RESET << std::endl;
}

template <typename T> void Array<T>::Print(void) {
	for (unsigned int i = 0; i < _n; i++)
		std::cout << arr[i] << std::endl;
}

template <typename T> int Array<T>::size(void) {
	int	count = 0;
	for (unsigned int i = 0; i < _n; i++)
		count++;
	return (count);
}

/* -+-+-+-+-+-+-+-+- Operators -+-+-+-+-+-+-+-+- */
template <typename T> T& Array<T>::operator[](unsigned int elem)
{
	if (elem >= _n)
		throw OutOfBounds();
	return (arr[elem]);
}
/* -+-+-+-+-+-+-+-+- Operators -+-+-+-+-+-+-+-+- */

/* /-/-/-/-/-/-/-/-/ Exceptions /-/-/-/-/-/-/-/-/ */
template <typename T> const char *Array<T>::OutOfBounds::what() const throw() {
	return ("Out of Bounds\n");
}
/* /-/-/-/-/-/-/-/-/ Exceptions /-/-/-/-/-/-/-/-/ */

#endif