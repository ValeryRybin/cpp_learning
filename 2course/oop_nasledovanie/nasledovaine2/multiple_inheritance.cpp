#include <iostream>

struct A {
    int data = 1;

    void desribe() {
        std::cout << "I am A" << std::endl;
    }

    virtual void foo() = 0;
};

struct B {
    int data = 2;

    void describe() {
        std::cout << "I am B" << std::endl;
    }

    virtual void bar() = 0;
};

struct Test: A, B {
    void foo() override {
        std::cout << "foo" << std::endl;
    }

    void bar() override {
        std::cout << "bar" << std::endl;
    }
};

int main() {
    Test test;
    test.describe();
    test.A::desribe();
    std::cout << test.A::data << std::endl;
}