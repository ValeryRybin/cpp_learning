#include <iostream>

template <typename T, unsigned int Size>
class StaticArray
{
    T data_[Size];

public:
    StaticArray() {}

    // read elements
    const T &operator[](unsigned int index) const
    {
        return data_[index];
    }

    // set elements
    T &operator[](unsigned int index)
    {
        return data_[index];
    }

    void Fill(const T &value);

    void Print() const;
};

// void StaticArray::Fill(const T& value) {
//     ...
// }

template <typename T, unsigned int Size>
void StaticArray<T, Size>::Fill(const T &value)
{
    for (unsigned int i = 0; i < Size; ++i)
    {
        data_[i] = value;
    }
}

template <typename T, unsigned int Size>
void StaticArray<T, Size>::Print() const
{
    for (unsigned int i = 0; i < Size; ++i)
    {
        std::cout << data_[i] << " ";
    }
    std::cout << "\n";
}

// alias
using IntArray2D = StaticArray<int, 2>;

template <typename T>
class StaticArray<T, 3>
{
    T data_[3];

public:
    StaticArray()
    {
        std::cout << "Specialization StaticArray<T, 3>" << "\n";
    }
};

int main()
{
    IntArray2D arr;
    arr[0] = 1;
    arr[1] = 2;
    arr.Print();

    StaticArray<int, 3> arr3;
}
