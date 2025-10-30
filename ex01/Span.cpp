#include "Span.hpp"
#include <iostream>

template <typename T>
Span<T>::Span() : _N(0)
{}

template <typename T>
Span<T>::Span(unsigned int N) : _N(N)
{}

template <typename T>
Span<T>::Span(const Span &other) : _N(other._N), _vec(other._vec)
{}

template <typename T>
Span<T> &Span<T>::operator=(const Span &other)
{
    if (this != &other)
    {
        _N = other._N;
        _vec = other._vec;
    }
    return *this;
}

template <typename T>
Span<T>::~Span() {}

template <typename T>
void Span<T>::addNumber(const T &value)
{
    if (_vec.size() >= _N)
        throw MaxNumberException();
    _vec.push_back(value);
}

template <typename T>
void Span<T>::addNumber(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end)
{
	if (_vec.size() + std::distance(begin, end) > this->_N)
		throw MaxNumberException();
	this->_vec.insert(_vec.begin(), begin, end);
}

template <typename T>
const T Span<T>::shortestSpan(void)
{
    if (this->_vec.size() < 2)
        throw NoSpanFoundException();
    std::vector<T> sorted = _vec;
    std::sort(sorted.begin(), sorted.end());
    int minDiff = sorted[1] - sorted[0];

    for (size_t i = 1; i < sorted.size() - 1; ++i)
    {
        int diff = sorted[i + 1] - sorted[i];
        if (diff < minDiff)
            minDiff = diff;
    }
    return (minDiff);
}

template <typename T>
const T Span<T>::longestSpan(void)
{
    if (this->_vec.size() < 2)
        throw NoSpanFoundException();
    T minVal = *std::min_element(_vec.begin(), _vec.end());
    T maxVal = *std::max_element(_vec.begin(), _vec.end());
    return (maxVal - minVal);
}

template <typename T>
const char* Span<T>::MaxNumberException::what() const throw()
{
    return ("Max number reached, can't add more");
}

template <typename T>
const char* Span<T>::NoSpanFoundException::what() const throw()
{
    return ("No span can be found here, move along sir");
}

template class Span<int>;
template class Span<unsigned int>;
template class Span<float>;
template class Span<double>;