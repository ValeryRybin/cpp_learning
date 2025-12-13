#include <new>
#include <iostream>
#include <algorithm>

template <typename T>
class Subvector
{
private:
    T *data;
    unsigned int size_;
    unsigned int capacity_;

public:
    Subvector() : data(nullptr), size_(0), capacity_(0) {}

    ~Subvector()
    {
        delete[] data;
    }

    bool push_back(T element)
    {
        if (this->size_ >= this->capacity_)
            if (!this->resize(this->capacity_ * 2 + 1))
                return false;
        this->data[this->size_] = element;
        this->size_++;
        return true;
    }

    T pop_back()
    {
        if (this->size_ == 0)
            throw std::out_of_range("Error: subvector is empty.");

        return this->data[--this->size_];
    }

    bool resize(unsigned int new_capacity)
    {
        if (new_capacity == 0)
        {
            delete[] this->data;
            this->data = nullptr;
            this->capacity_ = 0;
            this->size_ = 0;
            return true;
        }
        if (new_capacity == this->capacity_)
            return true;
        else
        {
            int *data = new (std::nothrow) int[new_capacity];
            if (!data)
                return false;
            for (unsigned int i = 0; i < std::min(this->size_, new_capacity); ++i)
            {
                data[i] = this->data[i];
            }
            this->size_ = std::min(this->size_, new_capacity);
            delete[] this->data;
            this->data = data;
            this->capacity_ = new_capacity;
        }
        return true;
    }

    void shrink_to_fit()
    {
        this->resize(this->size_);
    }

    void clear()
    {
        this->resize(0);
    }
    unsigned int size() const
    {
        return this->size_;
    }
    unsigned int capacity() const
    {
        return this->capacity_;
    }

    T &operator[](unsigned int index)
    {
        if (index >= this->size_)
            throw std::out_of_range("Index out of range");
        return this->data[index];
    }

    const T &operator[](unsigned int index) const
    {
        if (index >= this->size_)
            throw std::out_of_range("Index out of range");
        return this->data[index];
    }
};