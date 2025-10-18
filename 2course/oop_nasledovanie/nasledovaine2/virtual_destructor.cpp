#include <iostream>

struct Base {
    int* data;

    Base() {
        std::cout << "Base constructor" << std::endl;
        data = new int[10];
    }

    ~Base() {
        delete[] data;
        std::cout << "Base destructor" << std::endl;
    }
};

struct Child: Base {
    int* data;

    Child() {
        std::cout << "Child constructor" << std::endl;
        data = new int[100];
    }

    ~Child() {
        std::cout << "Child destructor" << std::endl;
        delete[] data;
    }
};

int main() {
    Base* a = new Child;
    delete a;
}