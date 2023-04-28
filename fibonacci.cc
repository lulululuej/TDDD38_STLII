#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

int main() {
    int N{};
    std::cout << "Enter N = ";
    std::cin >> N;

    std::vector<unsigned long long int> fibonacci(N); // define vector has size N and value = 0;
    std::generate(fibonacci.begin(), fibonacci.end(), [n = 1]() mutable {return n++;} ); // take a look at the generate function
    std::for_each(fibonacci.begin(), fibonacci.end(), [](const int& n) { std::cout << n << ' '; }); // take a look at the for_each function
    std::cout << "\n";
    /* default is std::minus<>() */
    //std::adjacent_difference(fibonacci.begin(), fibonacci.end(), std::next(fibonacci.begin()));
    std::adjacent_difference(fibonacci.begin(), fibonacci.end(), std::next(fibonacci.begin()), std::plus<>());
    std::for_each(fibonacci.begin(), fibonacci.end(), [](const int& n) { std::cout << n << ' '; });
}