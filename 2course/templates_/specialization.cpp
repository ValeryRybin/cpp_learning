#include <iostream>

template <typename T>
void print_to_std(const T &value)
{
    std::cout << "Template" << "\n";
    std::cout << value << "\n";
}

template <>
void print_to_std<bool>(const bool &value)
{
    std::cout << std::boolalpha;
    std::cout << "Specialization" << "\n";
    std::cout << value << "\n";
}

int main()
{
    print_to_std(1);
    print_to_std(1.1);
    print_to_std(true);
}