#include <iostream>
#include <vector>


template <typename T>
struct Node {
    T key;
    Node* left;
    Node* right;
};


template <typename T>
class Subset {
    Node<T>* root_;

public:
    Subset() {} // инициализация пустого дерева

    bool Insert(const T& key) {} // добавление элемента в дерево, дубли игнорировать (ничего не добавлять в дерево, если там уже есть элемент с таким же key) и возвращать false

    bool Remove(const T& key) {} // удаление элемента из дерева (если элемента не нашлось, то ничего не удалять и вернуть false)

    Node<T>* Find(const T& key) {} // поиск элемента в дереве, нужно вернуть указатель на элемент с тем же key или, если такого элемента не нашлось, то NULL

    unsigned int Size() {} // количество элементов в дереве

    unsigned int Height() {} // высота самого глубокого пути

    std::vector<T> DFS() {} //обход в глубину, возвращает std::vector из элементов

    ~Subset() {} // очистить всю используемую память
};