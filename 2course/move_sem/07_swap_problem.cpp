#include <iostream>

// Давайте попробуем реализовать теперь прострую вещь: 
// хочу поменять местами два Pointer'a
// Пишем функцию swap

template<typename T>
void copy_swap(T& a, T&b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
void move_swap(T& a, T&b) {
    T tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}

template<typename T>
class ScopedPointer {
	T *ptr_;
public:
	ScopedPointer(T *ptr = nullptr) : ptr_(ptr) {
    }

	~ScopedPointer() { 
        delete ptr_; 
    }

	ScopedPointer(const ScopedPointer& rhs) : 
		ptr_(new T{*rhs.ptr_}) {
            std::cout << "Copy Ctor with copy and allocation" << std::endl;
        }
	
	ScopedPointer& operator=(const ScopedPointer& rhs) {
		if (this == &rhs) return *this;
		delete [] ptr_;
		ptr_ = new T{*rhs.ptr_};
        std::cout << "Copy assign with copy and allocation" << std::endl;
		return *this;
	}

    ScopedPointer(ScopedPointer && rhs): ptr_(rhs.ptr_) {
        rhs.ptr_ = nullptr;
        std::cout << "Move Ctor without copy and allocation" << std::endl;
    }

    ScopedPointer& operator=(ScopedPointer && rhs){
        delete ptr_;
        ptr_ = rhs.ptr_;
        rhs.ptr_ = nullptr;
        std::cout << "Move Assign without copy and allocation" << std::endl;
        return *this;
    }

    T& Get() {
        return *ptr_;
    }
};

// 1) Нет move операторов
// 2) Есть  move операторы

// Что на экране?

int main() {
    ScopedPointer<int> p1{new int{10}};
    ScopedPointer<int> p2{new int{20}};
    std::cout << p1.Get() << " " << p2.Get() << std::endl;
    copy_swap<ScopedPointer<int>>(p1, p2);
    std::cout << p1.Get() << " " << p2.Get() << std::endl;
}
