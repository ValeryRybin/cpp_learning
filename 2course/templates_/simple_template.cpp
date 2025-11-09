#include <iostream>

void print_to_std(int x)
{
    std::cout << "int overload" << std::endl;
    std::cout << x << std::endl;
}

void print_to_std(double x)
{
    std::cout << "double overload" << std::endl;
    std::cout << x << std::endl;
}

template <typename T>
void print_to_std(T x)
{
    std::cout << "template instantiation" << std::endl;
    std::cout << x << std::endl;
}

template <typename T>
void print_to_std(T x, T y)
{
    std::cout << x << " ";
    std::cout << y << std::endl;
}

// template <typename T, typename U>
// void print_to_std(T x, U y) {
//     std::cout << x << " ";
//     std::cout << y << std::endl;
// }

int main()
{
    print_to_std(1);
    print_to_std(1.2);
    print_to_std("Hello, World!");
    // print_to_std(1, 1.2);
}