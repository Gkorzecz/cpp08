#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <string>

int main(void)
{
    std::vector<int> v;
    v.push_back(6);
    v.push_back(7);
    v.push_back(1);
    v.push_back(15);
    v.push_back(3);
    
    std::cout << "Not in vector :" << std::endl;
    try
    {
        easyfind(v, 5);
        easyfind(v, 18);
        std::cout << "All found !!" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << "\nIn vector :" << std::endl;
    try
    {
        easyfind(v, 1);
        easyfind(v, 15);
        std::cout << "All found !!" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}