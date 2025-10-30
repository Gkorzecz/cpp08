#include "Span.hpp"
#include <iostream>
#include <cstdlib> 
#include <ctime>

int main(void)
{
    int seed = time(NULL);
	srand(seed);

    std::cout << "BASIC TESTS :" << std::endl;
    Span<int> span(4);
    try
    {
        span.addNumber(-1);
        span.addNumber(3);
        span.addNumber(3);
        span.addNumber(5);
        std::cout << "Longest span is : " << span.longestSpan() << std::endl;
        std::cout << "Shortest span is : " << span.shortestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "BIG TESTS :" << std::endl;
    std::vector<int> vec_10000;
	for (size_t i = 0; i < 10000; ++i)
		vec_10000.push_back(rand());
    Span<int> span_10000(vec_10000.size());
    span_10000.addNumber(vec_10000.begin(), vec_10000.end());
    try
    {
        std::cout << "Longest span is : " << span_10000.longestSpan() << std::endl;
        std::cout << "Shortest span is : " << span_10000.shortestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}

// int main()
// {
// Span<int> sp = Span<int>(5);
// sp.addNumber(6);
// sp.addNumber(3);
// sp.addNumber(17);
// sp.addNumber(9);
// sp.addNumber(11);
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
// return 0;
// }