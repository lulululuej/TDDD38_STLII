#include <iostream>
#include <set>
#include <numeric>
#include <functional>
void put(int n) {
    std::cout << n << std::endl;
}

int fun1() { return 1; }
int fun2(int a) { return a*3; }

int main() {
    /*int array[3] {1,2,3};
    std::cout << array << std::endl; // print the address of first element;
    for(int e: array) {
        std::cout << e << std::endl;
    }

    auto it { std::begin(array) }; // same as the cout << array;
    auto last { std::end(array) };
    std::cout << it << ", " << last << std::endl;

    for(;it!=last; ++it) {
        std::cout << *it << std::endl;
        std::cout << it << std::endl;
    }*/

    /*std::istream_iterator<int> iit {std::cin}; // input int;
    std::istream_iterator<int> end {}; // no string;

    while(iit != end) {
        std::cout << *iit++ << std::endl;
    }*/

    /*std::ostream_iterator<int> oit {std::cout," "};
    *oit++ = 5;
    *oit++ = 6;
    *oit++ = 7;*/

    /*std::vector<int> v{1,2,3};
    auto f{[x=0](int n) mutable{
        std::cout << "x = " << x << ", n = " << n << std::endl;
        x += n;
        return x;
    }};*/
    /* lambda function practice */
    //auto lambda = [](void) -> void { std::cout << "Hello, Lambda" << std::endl; };
    //lambda();

    //std::for_each(v.begin(), v.end(), put);
    //std::for_each(v.begin(), v.end(), std::ref(f));
    //std::cout << f(50) << std::endl;

    /*std::set<std::string> v{"1", "2", "3"};
    int result{
        std::accumulate(std::begin(v), std::end(v), 4,
        [](int n, std::string const& s){
            return n + std::stoi(s);
        })
    };
    std::cout << result << std::endl;*/

    /*std::function<int()> fun{fun1};
    fun = std::bind([](int a, int b){
        return a+b;
    }, 1, fun());

    fun = [fun](){return 2 * fun();};

    std::cout << std::bind([](int x, int y, int z){
        std::cout << x << ", " << y << ", " << z << std::endl;
        return fun2(x)+y; 
        }, std::placeholders::_2, std::placeholders::_1, 17)(fun(), 3);*/


    std::function<int(int)> fun = [](int x)
    {
        std::cout << "fun x = " << x << std::endl;
        return x;
    };

    // fun has been overwrite
    // base get fun
    /*fun = std::bind([&fun, base = fun](int x, int y) 
            {
                std::cout << "x = " << x << ", y = " << y << std::endl; 
                if (y < x)
                {
                    std::cout << x << std::endl;
                    return fun(x - 1);
                }
                return base(x);
            }, std::placeholders::_1, 1); // x and y
        
    std::cout << fun(4) << std::endl;*/

    /*std::vector<int> v{1,2,3,4,4,4,5,5,6,7,7,8,9,9};
    auto last = std::unique(v.begin(), v.end());
    for(int i : v) {
        std::cout << i << std::endl;
    }
    // v now holds {1 2 1 3 4 5 4 x x x}, where 'x' is indeterminate
    v.erase(last, v.end());
    std::cout << "After Erase" << std::endl;
    for(int i : v) {
        std::cout << i << std::endl;
    }*/

    std::vector<int> v { 3, 4, 1, 12, 13 };
    std::copy_if(v.begin(), v.end(),
                 std::ostream_iterator<int>{std::cout, "_"},
                 [](int n)
                 {
                     //std::cout << n << std::endl;
                     return (n >> 2); //right shift 2 bits
                 });
}