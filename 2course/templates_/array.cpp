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

int main()
{
    StaticArray<double, 3> arr;
    arr.Print();
    arr[0] = 1.1;
    arr[1] = 2.2;
    arr[2] = 3.3;
    arr.Print();

    StaticArray<std::string, 2> str_arr;
    str_arr.Print();
    str_arr[0] = "Hello,";
    str_arr[1] = "World!";
    str_arr.Print();
}