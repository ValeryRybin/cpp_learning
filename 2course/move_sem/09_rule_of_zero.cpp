#include <iostream>

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
        std::cout << "Optor = with copy and allocation" << std::endl;
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

    const T& Get() const {
        return *ptr_;
    }
};


// Давайте рассмотрим структуру

struct Data {
    int a;
    char c;
    ScopedPointer<int> p;

    void Print() const {
        std::cout << a << " " << c << " " << p.Get() << std::endl;
    }
};

int main() {
    Data v1{10, 'a', ScopedPointer<int>{new int(10)}};
    Data v2{12, 'b', ScopedPointer<int>{new int(12)}};
    // v1 = v2;
    Data v3{v2};
    v1.Print();
    v2.Print();
    v1 = std::move(v2);
    v1.Print();
    v2.Print(); // ???
}

// Нужно ли что-то из тех 6 функций определять для Data?