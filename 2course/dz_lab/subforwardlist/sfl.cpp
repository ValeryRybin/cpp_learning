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
    ~Subforwardlist()
    {
        clear();
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

    int pop_back()
    {
        if (root == nullptr)
            return 0;
        if (root->next == nullptr)
        {
            int tmp = root->data;
            delete root;
            root = nullptr;
            return tmp;
        }
        Node *current_node = root;
        while (current_node->next->next != nullptr)
        {
            current_node = current_node->next;
        }
        int tmp = current_node->next->data;
        delete current_node->next;
        current_node->next = nullptr;
        return tmp;
    }

    void push_forward(int data)
    {
        Node *new_node = new Node();
        new_node->data = data;
        new_node->next = root;
        root = new_node;
    }

    int pop_forward()
    {
        if (root == nullptr)
            return 0;
        Node *first_node = root;
        int tmp = first_node->data;
        root = first_node->next;
        delete first_node;
        return tmp;
    }

    void push_where(unsigned int where, int data)
    {
        if (where == 1)
        {
            push_forward(data);
            return;
        }
        if (where > size() + 1)
        {
            std::cout << "Attention, the element has been added to the end of the subforwardlist." << std::endl;
            push_back(data);
            return;
        }
        Node *new_node = new Node();
        new_node->data = data;
        new_node->next = nullptr;

        Node *current_node = root;
        for (unsigned int i = 1; where > i + 1; ++i)
        {
            current_node = current_node->next;
        }
        new_node->next = current_node->next;
        current_node->next = new_node;
    }

    int erase_where(unsigned int where)
    {
        if (where > size() || root == nullptr)
            return 0;
        if (where <= 1)
            return pop_forward();

        Node *current_node = root;
        for (unsigned int i = 1; where > i + 1; ++i)
        {
            current_node = current_node->next;
        }
        Node *erased_node = current_node->next;
        int tmp = erased_node->data;
        current_node->next = current_node->next->next;
        delete erased_node;
        return tmp;
    }

    unsigned int size()
    {
        unsigned int size = 0;
        Node *current_node = root;
        while (current_node != nullptr)
        {
            ++size;
            current_node = current_node->next;
        }
        return size;
    }

    void clear()
    {
        Node *current_node = root;
        while (current_node != nullptr)
        {
            Node *next_node = current_node->next;
            delete current_node;
            current_node = next_node;
        }
        root = nullptr;
    }
};