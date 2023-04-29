#include <iostream>

template <typename T>
class Test{
    private:
        T number;
    public:
        Test(): number{}
        {
        };
    
        Test(T num): number {num}
        {
        };

        void printInfo() {
            std::cout << "number: " << number << std::endl;
        }
};

int main() {
    Test<int> x(1.33); // 1
    Test<double> y(1.33); // 1.33
    x.printInfo();
    y.printInfo();
}