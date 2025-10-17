#include <new>
#include <iostream>
#include <algorithm>

struct subvector
{
    int *data;
    unsigned int size;
    unsigned int capacity;
};

bool init(subvector *vec);
bool push_back(subvector *vec, int element);
int pop_back(subvector *vec);
bool resize(subvector *vec, unsigned int new_capacity);
void shrink_to_fit(subvector *vec);
void clear(subvector *vec);
void destructor(subvector *vec);

bool init(subvector *vec)
{
    vec->size = 0;
    vec->capacity = 0;
    vec->data = nullptr;
    return true;
}

bool push_back(subvector *vec, int element)
{
    if (!vec)
        return false;
    if (vec->size >= vec->capacity)
        if (!resize(vec, vec->capacity * 2 + 1))
            return false;
    vec->data[vec->size] = element;
    vec->size++;
    return true;
}

int pop_back(subvector *vec)
{
    if (!vec)
    {
        std::cout << "Error: null pointer passed to pop_back." << std::endl;
        return -1;
    }
    if (vec->size == 0)
    {
        std::cout << "Error: subvector is empty." << std::endl;
        return -1;
    }
    return vec->data[--vec->size];
}

bool resize(subvector *vec, unsigned int new_capacity)
{
    if (!vec)
        return false;
    if (new_capacity == 0)
    {
        delete[] vec->data;
        vec->data = nullptr;
        vec->capacity = 0;
        vec->size = 0;
        return true;
    }
    if (new_capacity == vec->capacity)
        return true;
    else
    {
        int *data = new (std::nothrow) int[new_capacity];
        if (!data)
            return false;
        for (unsigned int i = 0; i < std::min(vec->size, new_capacity); ++i)
        {
            data[i] = vec->data[i];
        }
        vec->size = std::min(vec->size, new_capacity);
        delete[] vec->data;
        vec->data = data;
        vec->capacity = new_capacity;
    }
    return true;
}

void shrink_to_fit(subvector *vec)
{
    resize(vec, vec->size);
}

void clear(subvector *vec)
{
    vec->size = 0;
    shrink_to_fit(vec);
}

void destructor(subvector *vec)
{
    if (vec)
        delete[] vec->data;
    init(vec);
}