#include <new>
#include <iostream>
#include <algorithm>

class Subvector
{
private:
    int *data;
    unsigned int size;
    unsigned int capacity;

public:
    Subvector() : data(nullptr), size(0), capacity(0) {}

    ~Subvector()
    {
        delete[] data;
    }

    bool push_back(int element)
    {
        if (this->size >= this->capacity)
            if (!this->resize(this->capacity * 2 + 1))
                return false;
        this->data[this->size] = element;
        this->size++;
        return true;
    }

    int pop_back()
    {
        if (this->size == 0)
            throw std::out_of_range("Error: subvector is empty.");

        return this->data[--this->size];
    }

    bool resize(unsigned int new_capacity)
    {
        if (new_capacity == 0)
        {
            delete[] this->data;
            this->data = nullptr;
            this->capacity = 0;
            this->size = 0;
            return true;
        }
        if (new_capacity == this->capacity)
            return true;
        else
        {
            int *data = new (std::nothrow) int[new_capacity];
            if (!data)
                return false;
            for (unsigned int i = 0; i < std::min(this->size, new_capacity); ++i)
            {
                data[i] = this->data[i];
            }
            this->size = std::min(this->size, new_capacity);
            delete[] this->data;
            this->data = data;
            this->capacity = new_capacity;
        }
        return true;
    }

    void shrink_to_fit()
    {
        this->resize(this->size);
    }

    void clear()
    {
        this->resize(0);
    }
};