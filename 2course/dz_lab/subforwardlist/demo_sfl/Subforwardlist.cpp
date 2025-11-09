#include <iostream>

struct Node
{
    int data;
    Node *next;
};

class Subforwardlist
{
private:
    Node *root;

public:
    Subforwardlist() : root(nullptr) {}

    void push_back(int data)
    {
        Node *new_node = new Node();
        new_node->data = data;
        new_node->next = nullptr;

        if (root == nullptr)
        {
            root = new_node;
            return;
        }

        Node *current_node = root;
        while (current_node->next != nullptr)
        {
            current_node = current_node->next;
        }

        current_node->next = new_node;
    }

    void print() const
    {
        if (root == nullptr)
        {
            std::cout << "Empty list!" << std::endl;
        }
        Node *current_node = root;
        while (current_node != nullptr)
        {
            std::cout << current_node->data << " ";
            current_node = current_node->next;
        }
        std::cout << std::endl;
    }

    int pop_back();                             // удаление элемента с конца недосписка, если пустой - возвращать 0
    void push_forward(int d);                   // добавление элемента в начало недосписка
    int pop_forward();                          // удаление элемента из начала недосписка, если пустой - возвращать 0
    void push_where(unsigned int where, int d); // добавление элемента с порядковым номером where
    int erase_where(unsigned int where);        // удаление элемента с порядковым номером where, если пустой - возвращать 0
    unsigned int size();                        // определить размер недосписка
    void clear();                               // очистить содержимое недосписка

    ~Subforwardlist(); // деструктор
};