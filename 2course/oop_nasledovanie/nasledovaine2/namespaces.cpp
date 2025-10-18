#include <iostream>

int x = 0;
void foo()
{
    std::cout << "foo" << std::endl;
}
struct S
{
    int data;
};

namespace A
{
    int x = 0;
    void foo()
    {
        std::cout << "A::foo" << std::endl;
    }
    struct S
    {
        int data;
    };
}

namespace B
{
    int x = 0;
    void foo()
    {
        std::cout << "B::foo" << std::endl;
    }
    struct S
    {
        int data;
    };

    namespace C
    {
        int x = 0;
        void foo()
        {
            std::cout << "B::C::foo" << std::endl;
        }

        struct S
        {
            int data;
        };
    }
}

// using namespace B;
// using A::foo;

int main()
{
    foo();
}