#include <iostream>
using namespace std;

class Animal
{
public:
    // Погладить данную зверушку.
    // Последствия зависят от реализации данного метода для класса конкретной зверушки.
    virtual void pet() = 0;

    virtual ~Animal() {};
};

class NPC
{
public:
    // Поговорить с NPC.
    // Что он скажет - зависит от реализации данного метода для конкретного NPC.
    virtual void talk() = 0;

    virtual ~NPC() {};
};

class SmartCat : public Animal, public NPC
{
public:
    void pet()
    {
        cout << "Meow!" << endl;
    }
    void talk()
    {
        cout << "Meow!" << endl;
    }
};