#include <algorithm>
#include <vector>
#include <initializer_list>
#include <functional>
#include <iostream>

// Implement Heap here

int main()
{

    {
        Heap<int> heap { 1, 3, 4, 7, 9, 10 };

        std::cout << "int heap with std::less:" << std::endl;

        std::cout << "\tCreation   : ";
        for (int v : heap)
        {
            std::cout << v << " ";
        }
        std::cout << std::endl;

        std::cout << "\tMax element: " << heap.front() << std::endl;
        
        heap.pop();
        
        std::cout << "\tAfter pop  : ";
        for (int v : heap)
        {
            std::cout << v << " ";
        }
        std::cout << std::endl;

        heap.push(11);
        
        std::cout << "\tPush 11    : ";
        for (int v : heap)
        {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }

    {
        Heap<std::string, std::greater<std::string>> heap { "A", "AB", "C", "DE", "EFG" };

        std::cout << "string heap with std::greater: " << std::endl;

        std::cout << "\tCreation   : ";
        for (std::string const& v : heap)
        {
            std::cout << v << " ";
        }
        std::cout << std::endl;

        std::cout << "\tMax element: " << heap.front() << std::endl;
        
        heap.pop();
        
        std::cout << "\tAfter pop  : ";
        for (std::string const& v : heap)
        {
            std::cout << v << " ";
        }
        std::cout << std::endl;

        heap.push("CD");
        
        std::cout << "\tPush \"CD\"  : ";
        for (std::string const& v : heap)
        {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
    
}
