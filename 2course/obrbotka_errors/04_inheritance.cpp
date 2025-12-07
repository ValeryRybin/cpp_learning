#include <iostream>
#include <string>

class Error {
protected:
    const char * string;
public:
    Error(const char * value): string(value) {}
    virtual const char * what() {return string;}
    virtual ~Error() {};
};

class MathError: public Error {
public:
    MathError(const char * string): Error(string) {}
    const char * what() override {
        return (std::string("Math Error: ") + std::string(string)).c_str();
    }
};

double divide(double x, double y) {
    if (std::abs(y) < 1e-16)
        throw MathError("Division by zero");
    return x / y;
}

int main() {
    try {
        double res = divide(1, 0);
    }
    // Ловим по ссылке
    catch (MathError& e) {
        std::cout << e.what() << std::endl;
    }
    // Ловить можно так же по ссылке на базовый класс
    catch (Error& e) {
        std::cout << e.what() << std::endl;
    }
}

// Ловля исключений по ссылку на базовый класс 
// является самым важным механизмом, поскольку
// именно он позволяет устраивать логику
// в обобщенной обработке ошибок разных типов