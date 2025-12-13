#include <iostream>
#include "Subset2.cpp"
int main()
{
    std::cout << "Test 1: Basic output works" << std::endl;

    std::cout << "Test 2: Subset2.cpp included" << std::endl;

    Subset<int> tree;
    std::cout << "Test 3: Subset created" << std::endl;

    tree.Insert(10);
    std::cout << "Test 4: Insert works" << std::endl;

    return 0;
}
