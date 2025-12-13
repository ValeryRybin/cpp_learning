#include <new>
#include <iostream>
#include <algorithm>

template <typename T>
class Subqueue
{
private:
    T *data;
    unsigned int size_;
    unsigned int capacity;
    unsigned int head;
    unsigned int tail;
    bool resize(unsigned int new_capacity)
    {
        if (new_capacity == 0)
        {
            delete[] this->data;
            this->data = nullptr;
            this->capacity = 0;
            this->size_ = 0;
            this->head = 0;
            this->tail = 0;
            return true;
        }
        if (new_capacity == this->capacity)
            return true;
        else
        {
            T *data = new (std::nothrow) T[new_capacity];
            if (!data)
                return false;
            for (unsigned int i = 0; i < std::min(this->size_, new_capacity); ++i)
            {
                unsigned int idx = (this->head + i) % (this->capacity);
                data[i] = this->data[idx];
            }
            this->size_ = std::min(this->size_, new_capacity);
            delete[] this->data;
            this->data = data;
            this->capacity = new_capacity;
            this->head = 0;
            this->tail = this->size_;
        }
        return true;
    }

public:
    Subqueue() : data(nullptr), size_(0), capacity(0), head(0), tail(0) {}
    ~Subqueue() { delete[] data; }
    // Конструктор копирования
    Subqueue(const Subqueue &other)
        : data(nullptr), head(0), tail(0), size_(0), capacity(0)
    {
        if (other.size_ > 0)
        {
            resize(other.capacity);
            for (unsigned int i = 0; i < other.size_; ++i)
            {
                unsigned int idx = (other.head + i) % other.capacity;
                this->push(other.data[idx]);
            }
        }
    }

    // Оператор присваивания
    Subqueue &operator=(const Subqueue &other)
    {
        if (this != &other)
        {
            delete[] this->data;
            this->data = nullptr;
            this->head = 0;
            this->tail = 0;
            this->size_ = 0;
            this->capacity = 0;

            if (other.size_ > 0)
            {
                resize(other.capacity);
                for (unsigned int i = 0; i < other.size_; ++i)
                {
                    unsigned int idx = (other.head + i) % other.capacity;
                    this->push(other.data[idx]);
                }
            }
        }
        return *this;
    }

    bool push(T element)
    {
        if (this->size_ >= this->capacity)
            if (!this->resize(this->capacity * 2 + 1))
                return false;
        this->data[this->tail] = element;
        this->tail = (this->tail + 1) % this->capacity;
        ++this->size_;
        return true;
    }
    T pop()
    {
        if (this->size_ == 0)
            throw std::out_of_range("Error: subqueue is empty.");

        T result = this->data[this->head];
        this->head = (this->head + 1) % this->capacity;
        --this->size_;
        return result;
    }
    T front()
    {
        if (this->size_ == 0)
            throw std::out_of_range("Error: subvector is empty.");

        return this->data[this->head];
    }
    bool empty() const { return (this->size_ == 0); }
    unsigned int size() const { return this->size_; }
    void clear()
    {
        this->resize(0);
    }
};