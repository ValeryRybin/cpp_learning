#include <iostream>

struct MyClass {
	int a = 0;
	int b = 1;
	int c = 2;
};

// int main() {
// 	MyClass* mc = new MyClass{0, 10, 20};
// 	delete mc; // приходится самому удалять память
// }

// Напишем класс, который будет сам менеджить память
// без нашего участия

template<typename T>
class ScopedPointer {
	T *ptr_;
public:
    // Конструктор
	ScopedPointer(T *ptr = nullptr) : ptr_(ptr) {}
	// Деструктор
    ~ScopedPointer() { delete ptr_; }

	// Getters 
	T& get() {return *ptr_;}
	const T& get() const { return *ptr_; }

	ScopedPointer(const ScopedPointer& other) {
		ptr_ = new T;
		*ptr_ = *(other.ptr_); 
	}

	ScopedPointer<T>& operator=(const ScopedPointer<T>& rhs) {
		*ptr_ = *(rhs.ptr_);
		return *this;
	}
};



int main() {
	ScopedPointer<MyClass> ptr(new MyClass{10, 20, 30});
	ScopedPointer<MyClass> ptr2(new MyClass{20, 50, 70});
	ptr = ptr2;
	ScopedPointer<MyClass> ptr3(ptr);
}
