#include <algorithm>
#include <vector>
#include <initializer_list>
#include <functional>
#include <iostream>

template <typename T, typename Compare = std::less<T>>
class Heap
{

public:

    // Required for it to be a container
    using value_type = T;
    using reference = T&;
    using const_reference = T const&;
    using iterator = typename std::vector<T>::iterator;
    using const_iterator = typename std::vector<T>::const_iterator;
    using difference_type = typename std::vector<T>::difference_type;
    using size_type = typename std::vector<T>::size_type;

    // Required for it to be a container
    Heap(Compare compare = {})
        : data { }, compare { }
    {
    }
    
    Heap(std::initializer_list<T> values, Compare compare = {})
        : data { values.begin(), values.end() }, compare { compare }
    {
        std::make_heap(std::begin(data), std::end(data), compare);
    }
    
    void push(T const& value)
    {
        data.push_back(value);
        std::push_heap(std::begin(data), std::end(data), compare);
    }
    
    void pop()
    {
        std::pop_heap(std::begin(data), std::end(data), compare);
        data.pop_back();
    }
    
    const_reference front() const
    {
        return data.front();
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

    // Required for it to be a container
    const_iterator cbegin() const
    {
        return begin();
    }

    // Required for it to be a container
    const_iterator cend() const
    {
        return end();
    }
    
    // Required for it to be a container
    bool empty() const
    {
        return data.empty();
    }
    
    // Required for it to be a container
    size_type size() const
    {
        return data.size();
    }
    
    // Required for it to be a container
    bool operator==(Heap<T, Compare> const& other) const
    {
        return data == other.data;
    }

    // Required for it to be a container
    bool operator!=(Heap<T, Compare> const& other) const
    {
        return !(*this == other);
    }

    // Required for it to be a container
    void swap(Heap<T, Compare>& other)
    {
        std::swap(compare, other.compare);
        std::swap(data, other.data);
    }
    
private:

    std::vector<T> data;
    Compare compare;
    
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