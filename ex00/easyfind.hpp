#pragma once 

# include <algorithm>

class NoValueFoundExeption : public std::exception
{
    virtual const char* what() const throw()
    {
        return ("Value Not Found");
    }

};

template <typename T>
typename T::iterator easyfind(T container, int value)
{
	typename T::iterator iter;

	iter = std::find(container.begin(), container.end(), value);
	if (iter == container.end())
		throw NoValueFoundExeption();
	return (iter);
}