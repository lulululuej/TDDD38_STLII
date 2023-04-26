#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

int main() {
    int N{};
    std::cout << "Enter N = ";
    std::cin >> N;

    std::vector<unsigned long long int> fibonacci(N);
    std::generate(fibonacci.begin(), fibonacci.end(), [n = 1]() mutable {return n++;} );
    std::for_each(fibonacci.begin(), fibonacci.end(), [](const int& n) { std::cout << n << ' '; });
    std::cout << "\n";
    /* default is std::minus<>() */
    //std::adjacent_difference(fibonacci.begin(), fibonacci.end(), std::next(fibonacci.begin()));
    std::adjacent_difference(fibonacci.begin(), fibonacci.end(), std::next(fibonacci.begin()), std::plus<>());
    std::for_each(fibonacci.begin(), fibonacci.end(), [](const int& n) { std::cout << n << ' '; });
}