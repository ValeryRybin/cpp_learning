#include <iostream>
#include <vector>

template <typename T>
struct Node
{
    T key_;
    Node *left_;
    Node *right_;
    Node *parent_;
};

template <typename T>
class Subset
{
    Node<T> *root_;
    unsigned int size_;
    unsigned int Height_Calc(Node<T> *node) const
    {
        if (node == nullptr)
            return 0;
        else
        {
            unsigned int hL = Height_Calc(node->left_);
            unsigned int hR = Height_Calc(node->right_);
            return 1 + (hL >= hR ? hL : hR);
        }
    }
    void Destroy(Node<T> *node)
    {
        if (node == nullptr)
            return;
        Destroy(node->left_);
        Destroy(node->right_);
        delete node;
    }
    void EraseNode(Node<T> *node)
    {
        Node<T> *parent = node->parent_;

        if (!node->left_ && !node->right_)
        {
            if (parent == nullptr)
                root_ = nullptr;
            else if (node == parent->left_)
                parent->left_ = nullptr;
            else
                parent->right_ = nullptr;
            delete node;
            --size_;
        }

        else if (!node->left_ != !node->right_)
        {
            Node<T> *child = (node->left_ != nullptr ? node->left_ : node->right_);
            if (!parent)
            {
                root_ = child;
                child->parent_ = nullptr;
            }
            else if (parent->left_ == node)
            {
                parent->left_ = child;
                child->parent_ = parent;
            }
            else
            {
                parent->right_ = child;
                child->parent_ = parent;
            }
            delete node;
            --size_;
        }
        else
        {
            Node<T> *succ = node->right_;
            while (succ->left_)
                succ = succ->left_;
            node->key_ = succ->key_;
            EraseNode(succ);
        }
    }

public:
    Subset() : root_(nullptr), size_(0) {}
    class iterator
    {
        Node<T> *node_;

    public:
        iterator(Node<T> *node) : node_(node) {}

        const T &operator*() const { return node_->key_; }
        iterator &operator++()
        {
            if (node_->right_ != nullptr)
            {
                node_ = node_->right_;
                while (node_->left_ != nullptr)
                    node_ = node_->left_;
            }
            else
            {
                Node<T> *current = node_;
                Node<T> *parent = node_->parent_;
                while (parent != nullptr && current == parent->right_)
                {
                    current = parent;
                    parent = parent->parent_;
                }
                node_ = parent;
            }
            return *this;
        }
        bool operator==(const iterator &other) const { return node_ == other.node_; }
        bool operator!=(const iterator &other) const { return node_ != other.node_; }
    };
    iterator begin() const
    {
        if (root_ == nullptr)
            return iterator(nullptr);
        Node<T> *current = root_;
        while (current->left_ != nullptr)
            current = current->left_;
        return iterator(current);
    }
    iterator end() const
    {
        return iterator(nullptr);
    }
    bool Insert(const T &key)
    {
        if (root_ == nullptr)
        {
            Node<T> *newnode = new Node<T>;
            root_ = newnode;
            newnode->key_ = key;
            newnode->left_ = nullptr;
            newnode->right_ = nullptr;
            newnode->parent_ = nullptr;
            size_++;
            return true;
        }
        else
        {
            Node<T> *current = root_;
            Node<T> *parent = nullptr;
            while (current != nullptr)
            {
                if (current->key_ == key)
                    return false;
                parent = current;
                if (current->key_ > key)
                {
                    current = current->left_;
                }
                else
                {
                    current = current->right_;
                }
            }
            Node<T> *newnode = new Node<T>;
            newnode->parent_ = parent;
            newnode->key_ = key;
            newnode->left_ = nullptr;
            newnode->right_ = nullptr;
            if (parent->key_ > key)
                parent->left_ = newnode;
            else
                parent->right_ = newnode;
            size_++;
            return true;
        }
    }
    bool Remove(const T &key)
    {
        Node<T> *node = Find(key);
        if (!node)
            return false;
        EraseNode(node);
        return true;
    }
    Node<T> *Find(const T &key) const
    {
        Node<T> *current = root_;

        while (current != nullptr)
        {
            if (current->key_ == key)
                return current;
            else if (current->key_ > key)
                current = current->left_;
            else
                current = current->right_;
        }
        return nullptr;
    }
    unsigned int Size() const
    {
        return size_;
    }
    unsigned int Height() const
    {
        return Height_Calc(root_);
    }
    std::vector<T> DFS() const
    {
        std::vector<T> vec;
        for (auto it = begin(); it != end(); ++it)
        {
            vec.push_back(*it);
        }
        return vec;
    }
    ~Subset()
    {
        Destroy(root_);
        root_ = nullptr;
        size_ = 0;
    }
};