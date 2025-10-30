#pragma once

# include <vector>
# include <exception>
# include <algorithm>

template <typename T>
class Span
{
private:
    unsigned int _N;
    std::vector<T> _vec;

public:
    Span();
    explicit Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(const T &value);
    void addNumber(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end);
    const T shortestSpan(void);
    const T longestSpan(void);

    class MaxNumberException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    class NoSpanFoundException : public std::exception
    {
    public:
        const char* what() const throw();
    };
};