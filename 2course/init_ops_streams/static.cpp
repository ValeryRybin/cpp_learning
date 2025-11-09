#include <iostream>

// Локальные статические переменные
void count_calls() {
    static int calls = 0;
    calls += 1;
    std::cout << "Вызов №" << calls << std::endl;
}

// Статические поля класса
class MyClass {
public:
    static int count;
    MyClass() { count++; }
};

int MyClass::count = 0;

// Статические методы класса
class MathUtils {
public:
    static int add(int a, int b) {
        return a + b;
    }

    static void printCount() {
        std::cout << "Count: " << count << std::endl; // OK: count — static
        // std::cout << value; // ОШИБКА: value — нестатический член
    }

private:
    static int count;
    int value = 0;
};

int MathUtils::count = 0;

// main
int main() {
    count_calls();
    count_calls();
    count_calls();
    count_calls();
    count_calls();

    MyClass a, b, c;
    std::cout << MyClass::count << std::endl;
    
    int result = MathUtils::add(3, 4);
    MathUtils::printCount();
}