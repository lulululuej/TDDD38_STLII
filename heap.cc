#include <algorithm>
#include <vector>
#include <initializer_list>
#include <functional>
#include <iostream>

// Implement Heap here
template <typename T, typename Compare = std::less<T>>
class Heap {
    private:
        std::vector<T> data; // value of constructor
        Compare compare;
    public:
        using const_iterator = typename std::vector<T>::const_iterator;
        // Required for it to be a container
        Heap(Compare compare = {}) 
            : data { }, compare { } // default value of constructor
        {
        }
        Heap(std::initializer_list<T> values, Compare compare = {})
            : data { values.begin(), values.end() }, compare { compare }
        {
            std::make_heap(std::begin(data), std::end(data), compare);
        }
            // Required for it to be a container
        const_iterator begin() const
        {
            return std::begin(data);
        }

        // Required for it to be a container
        const_iterator end() const
        {
            return std::end(data);
        }

        T const& front() {
            return data.front();
        };

        void pop() {
            std::pop_heap(data.begin(), data.end(), compare);
            data.pop_back();
        };

        void push(T&& d) {
            data.push_back(d);
            std::push_heap(data.begin(), data.end(), compare);
        };

        bool operator==(Heap<T, Compare> const& other) {
            return data == other.data;
        }

        bool operator!=(Heap<T, Compare> const& other) {
            return !(data == other.data);
        }
};

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
