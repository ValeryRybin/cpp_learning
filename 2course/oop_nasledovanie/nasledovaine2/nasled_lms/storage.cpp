class Storage
{
private:
    unsigned int size;
    int *data;

public:
    // Конструктор хранилища размерности n
    Storage(unsigned int n)
    {
        data = new int[n];
        size = n;
    }
    virtual ~Storage()
    {
        delete[] data;
    }
    // Добавьте нужный деструктор

    // Получение размерности хранилища
    unsigned getSize()
    {
        return size;
    }

    // Получение значения i-го элемента из хранилища,
    // i находится в диапазоне от 0 до n-1,
    // случаи некорректных i можно не обрабатывать.
    int getValue(unsigned int i)
    {
        return data[i];
    }

    // Задание значения i-го элемента из хранилища равным value,
    // i находится в диапазоне от 0 до n-1,
    // случаи некорректных i можно не обрабатывать.
    void setValue(unsigned int i, int value)
    {
        data[i] = value;
    }
};