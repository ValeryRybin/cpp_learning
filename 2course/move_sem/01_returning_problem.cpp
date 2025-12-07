// Теперь обсудим move семантику в С++
// Попробуем её изобрести

#include <iostream>

struct MyClass {
	int a = 0;
	int b = 1;
	int c = 2;
};

template<typename T>
class ScopedPointer {
	T *ptr_;
public:
    // Конструктор
	ScopedPointer(T *ptr = nullptr) : ptr_(ptr) {}
	// Деструктор
    ~ScopedPointer() { delete ptr_; }
    // Конструктор копирования
    ScopedPointer(const ScopedPointer& other): ptr_(new T(*(other.ptr_))) {
        std::cout << "Copy ctor with memory alloc" << std::endl;
    }
    // Оператор присаваивания
    ScopedPointer& operator=(const ScopedPointer& other) {
        std::cout << "Assign opt with memory alloc" << std::endl;

        if (this == &other) return *this;
        delete ptr_;
        ptr_ = new T(*(other.ptr_));
        return *this; 
    }
};


// Конструктор копирования и оператор присваивания создают полнyю 
// копию из переданного объекта rhs.

// Это называется глубоким копированием: 
// после приваивания (копирования) объект полность 
// идентичен объекту справа от знака = (аргумента конструктора).

// Это отлично получилось сделать в прошлый раз с помощью 
// контрукторов копирования и операторов присваивания.

// Пусть теперь есть функция, которая возвращает экземпляр объекта vector
ScopedPointer<MyClass> foo() {
    ScopedPointer<MyClass> res{new MyClass{20, 20, 20}};
    // ..something.. //
    return res;
}

// И посмотрим на следующий код

int main() {
    ScopedPointer<MyClass> p1{new MyClass{1, 2, 3}};
    ScopedPointer<MyClass> p2{new MyClass{4, 5, 6}};

    // ... something... //

    std::cout << "Хотим глубокое копирование" << std::endl;
    p2 = p1;
    // вот тут я действительно хочу глубокое копирование

    // ...some code... //

    std::cout << "Хотим глубокое копирование?" << std::endl; 
    p2 = foo();  

    // хочу ли я здесь глубокое копирование?
    // кажется, что нет, поскольку функция foo() вернет объект, 
    // который присвоится и умрет в этой же строчке кода

    // тут происходит большой перерасход 
    // Объект foo() умирает в конце полного выражение, он есть временный объект. 
    // А мы зачем-то обходимся с ним так, как будто он нам нужен где-то дальше по коду
}