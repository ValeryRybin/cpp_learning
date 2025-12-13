#include <iostream>
#include <vector>
#include "../subqueue/subqueue.cpp"
#include "../subvector/subvector_class.cpp"

template <typename T>
struct Node
{
    T key_;
    Node *left_;
    Node *right_;
    Node *parent_;
    bool is_red_;
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
            bool was_red = node->is_red_;
            if (parent == nullptr)
                root_ = nullptr;
            else if (node == parent->left_)
                parent->left_ = nullptr;
            else
                parent->right_ = nullptr;
            delete node;
            --size_;
            if (!was_red && parent)
                FixDelete(nullptr, parent);
        }
        else if (!node->left_ != !node->right_)
        {
            Node<T> *child = (node->left_ != nullptr ? node->left_ : node->right_);
            bool was_red = node->is_red_;
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
            if (!was_red)
                FixDelete(child, child->parent_);
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
    void Print(Node<T> *node, int depth) const
    {
        struct QueueItem
        {
            Node<T> *node;
            int depth;
        };
        Subqueue<QueueItem> queue;
        queue.push({node, depth});
        int current_depth = depth;
        while (!queue.empty())
        {
            QueueItem item = queue.pop();
            if (item.depth > current_depth)
            {
                std::cout << '\n';
                current_depth = item.depth;
            }
            std::cout << item.node->key_ << " ";
            if (item.node->left_)
            {
                queue.push({item.node->left_, item.depth + 1});
            }
            if (item.node->right_)
            {
                queue.push({item.node->right_, item.depth + 1});
            }
        }
    }
    void RotateLeft(Node<T> *node)
    {
        Node<T> *newnode = node->right_;
        node->right_ = newnode->left_;
        if (node->right_ != nullptr)
            node->right_->parent_ = node;
        newnode->parent_ = node->parent_;
        if (!node->parent_)
            root_ = newnode;
        else if (node == node->parent_->left_)
            node->parent_->left_ = newnode;
        else
            node->parent_->right_ = newnode;
        newnode->left_ = node;
        node->parent_ = newnode;
    }
    void RotateRight(Node<T> *node)
    {
        Node<T> *newnode = node->left_;
        node->left_ = newnode->right_;
        if (node->left_ != nullptr)
            node->left_->parent_ = node;
        newnode->parent_ = node->parent_;
        if (!node->parent_)
            root_ = newnode;
        else if (node == node->parent_->right_)
            node->parent_->right_ = newnode;
        else
            node->parent_->left_ = newnode;
        newnode->right_ = node;
        node->parent_ = newnode;
    }
    void FixInsert(Node<T> *node)
    {
        while (node != root_ && node->parent_ && node->parent_->is_red_)
        {
            Node<T> *parent = node->parent_;
            Node<T> *grandparent = GetGrandparent(node);
            if (!grandparent)
                break;
            if (parent == grandparent->left_)
            {
                Node<T> *uncle = grandparent->right_;
                if (uncle && uncle->is_red_)
                {
                    parent->is_red_ = false;
                    uncle->is_red_ = false;
                    grandparent->is_red_ = true;
                    node = grandparent;
                }
                else
                {
                    if (node == parent->right_)
                    {
                        node = parent;
                        RotateLeft(node);
                        parent = node->parent_;
                    }
                    if (parent)
                        parent->is_red_ = false;
                    if (grandparent)
                        grandparent->is_red_ = true;
                    RotateRight(grandparent);
                }
            }
            else
            {
                Node<T> *uncle = grandparent->left_;
                if (uncle && uncle->is_red_)
                {
                    parent->is_red_ = false;
                    uncle->is_red_ = false;
                    grandparent->is_red_ = true;
                    node = grandparent;
                }
                else
                {
                    if (node == parent->left_)
                    {
                        node = parent;
                        RotateRight(node);
                        parent = node->parent_;
                    }
                    if (parent)
                        parent->is_red_ = false;
                    if (grandparent)
                        grandparent->is_red_ = true;
                    RotateLeft(grandparent);
                }
            }
        }
        root_->is_red_ = false;
    }
    void FixDelete(Node<T> *node, Node<T> *parent)
    {
        while (node != root_ && (!node || !node->is_red_))
        {
            if (!parent)
                break;
            if (!node || node == parent->left_)
            {
                Node<T> *sibling = parent->right_;
                if (sibling && sibling->is_red_)
                {
                    sibling->is_red_ = false;
                    parent->is_red_ = true;
                    RotateLeft(parent);
                    sibling = parent->right_;
                }
                if (sibling &&
                    (!sibling->left_ || !sibling->left_->is_red_) &&
                    (!sibling->right_ || !sibling->right_->is_red_))
                {
                    sibling->is_red_ = true;
                    node = parent;
                    parent = node->parent_;
                }
                else if (sibling)
                {
                    if (!sibling->right_ || !sibling->right_->is_red_)
                    {
                        if (sibling->left_)
                            sibling->left_->is_red_ = false;
                        sibling->is_red_ = true;
                        RotateRight(sibling);
                        sibling = parent->right_;
                    }
                    sibling->is_red_ = parent->is_red_;
                    parent->is_red_ = false;
                    if (sibling->right_)
                        sibling->right_->is_red_ = false;
                    RotateLeft(parent);
                    node = root_;
                    break;
                }
            }
            else
            {
                Node<T> *sibling = parent->left_;
                if (sibling && sibling->is_red_)
                {
                    sibling->is_red_ = false;
                    parent->is_red_ = true;
                    RotateRight(parent);
                    sibling = parent->left_;
                }
                if (sibling &&
                    (!sibling->right_ || !sibling->right_->is_red_) &&
                    (!sibling->left_ || !sibling->left_->is_red_))
                {
                    sibling->is_red_ = true;
                    node = parent;
                    parent = node->parent_;
                }
                else if (sibling)
                {
                    if (!sibling->left_ || !sibling->left_->is_red_)
                    {
                        if (sibling->right_)
                            sibling->right_->is_red_ = false;
                        sibling->is_red_ = true;
                        RotateLeft(sibling);
                        sibling = parent->left_;
                    }
                    sibling->is_red_ = parent->is_red_;
                    parent->is_red_ = false;
                    if (sibling->left_)
                        sibling->left_->is_red_ = false;
                    RotateRight(parent);
                    node = root_;
                    break;
                }
            }
        }
        if (node)
            node->is_red_ = false;
    }

    Node<T> *GetUncle(Node<T> *node)
    {
        if (!node || !node->parent_)
            return nullptr;
        return GetBrother(node->parent_);
    }
    Node<T> *GetBrother(Node<T> *node)
    {
        if (!node || !node->parent_)
            return nullptr;
        return node->parent_->right_ == node ? node->parent_->left_ : node->parent_->right_;
    }
    Node<T> *GetGrandparent(Node<T> *node)
    {
        if (!node || !node->parent_)
            return nullptr;
        return node->parent_->parent_;
    }

    struct SplitResult
    {
        Node<T> *left;
        Node<T> *right;
    };
    int GetBlackHeight(Node<T> *node) const
    {
        if (!node)
            return 0;
        int height = 0;
        Node<T> *current = node;
        while (current)
        {
            if (!current->is_red_)
                ++height;
            current = current->left_;
        }
        return height;
    }
    SplitResult Split(Node<T> *node, const T &key)
    {
        if (!node)
            return {nullptr, nullptr};
        if (node->key_ < key)
        {
            auto result = Split(node->right_, key);
            node->right_ = result.left;
            if (result.left)
                result.left->parent_ = node;
            result.left = node;
            node->parent_ = nullptr;
            return result;
        }
        else
        {
            auto result = Split(node->left_, key);
            node->left_ = result.right;
            if (result.right)
                result.right->parent_ = node;
            result.right = node;
            node->parent_ = nullptr;
            return result;
        }
    }
    Node<T> *InsertNodeIntoTree(Node<T> *tree, Node<T> *node)
    {
        if (!tree)
        {
            node->parent_ = nullptr;
            node->left_ = nullptr;
            node->right_ = nullptr;
            node->is_red_ = false;
            return node;
        }
        Node<T> *current = tree;
        Node<T> *parent = nullptr;
        while (current)
        {
            parent = current;
            if (node->key_ < current->key_)
                current = current->left_;
            else
                current = current->right_;
        }
        node->parent_ = parent;
        node->left_ = nullptr;
        node->right_ = nullptr;
        node->is_red_ = true;
        if (node->key_ < parent->key_)
            parent->left_ = node;
        else
            parent->right_ = node;
        FixInsert(node);
        while (node->parent_)
            node = node->parent_;
        return node;
    }
    Node<T> *Join(Node<T> *left, Node<T> *middle, Node<T> *right)
    {
        if (!left)
            return InsertNodeIntoTree(right, middle);
        if (!right)
            return InsertNodeIntoTree(left, middle);
        int h_left = GetBlackHeight(left);
        int h_right = GetBlackHeight(right);
        if (h_left == h_right)
        {
            middle->left_ = left;
            middle->right_ = right;
            middle->parent_ = nullptr;
            middle->is_red_ = false;
            left->parent_ = middle;
            right->parent_ = middle;
            return middle;
        }
        else if (h_left > h_right)
        {
            Node<T> *current = left;
            Node<T> *parent = nullptr;
            int current_height = h_left;
            while (current && current_height > h_right)
            {
                parent = current;
                current = current->right_;
                if (current && !current->is_red_)
                    current_height--;
            }
            middle->left_ = current;
            middle->right_ = right;
            middle->parent_ = parent;
            middle->is_red_ = true;
            if (parent)
                parent->right_ = middle;
            if (current)
                current->parent_ = middle;
            if (right)
                right->parent_ = middle;
            Node<T> *root = left;
            while (root->parent_)
                root = root->parent_;
            Node<T> *old_root = root_;
            root_ = root;
            FixInsert(middle);
            root = root_;
            root_ = old_root;
            return root;
        }
        else
        {
            Node<T> *current = right;
            Node<T> *parent = nullptr;
            int current_height = h_right;
            while (current && current_height > h_left)
            {
                parent = current;
                current = current->left_;
                if (current && !current->is_red_)
                    current_height--;
            }
            middle->left_ = left;
            middle->right_ = current;
            middle->parent_ = parent;
            middle->is_red_ = true;
            if (parent)
                parent->left_ = middle;
            if (left)
                left->parent_ = middle;
            if (current)
                current->parent_ = middle;
            Node<T> *root = right;
            while (root->parent_)
                root = root->parent_;
            Node<T> *old_root = root_;
            root_ = root;
            FixInsert(middle);
            root = root_;
            root_ = old_root;
            return root;
        }
    }
    Node<T> *MergeNodes(Node<T> *t1, Node<T> *t2)
    {
        if (!t1)
            return t2;
        if (!t2)
            return t1;
        Node<T> *middle = t1;
        Node<T> *t1_left = t1->left_;
        Node<T> *t1_right = t1->right_;
        if (t1_left)
            t1_left->parent_ = nullptr;
        if (t1_right)
            t1_right->parent_ = nullptr;
        middle->left_ = nullptr;
        middle->right_ = nullptr;
        middle->parent_ = nullptr;
        auto split_result = Split(t2, middle->key_);
        Node<T> *new_left = MergeNodes(t1_left, split_result.left);
        Node<T> *new_right = MergeNodes(t1_right, split_result.right);
        return Join(new_left, middle, new_right);
    }
    unsigned int CountNodes(Node<T> *node) const
    {
        if (!node)
            return 0;
        return 1 + CountNodes(node->left_) + CountNodes(node->right_);
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
            newnode->is_red_ = true;
            root_ = newnode;
            newnode->key_ = key;
            newnode->left_ = nullptr;
            newnode->right_ = nullptr;
            newnode->parent_ = nullptr;
            size_++;
            FixInsert(newnode);
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
            newnode->is_red_ = true;
            newnode->parent_ = parent;
            newnode->key_ = key;
            newnode->left_ = nullptr;
            newnode->right_ = nullptr;
            if (parent->key_ > key)
                parent->left_ = newnode;
            else
                parent->right_ = newnode;
            size_++;
            FixInsert(newnode);
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
    Subvector<T> DFS() const
    {
        Subvector<T> vec;
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
    void print_subset() const
    {
        Print(root_, 0);
    }
    Subqueue<T> BFS() const
    {
        Subqueue<T> result;
        if (root_ == nullptr)
            return result;
        Subqueue<Node<T> *> work_queue;
        work_queue.push(root_);
        while (!work_queue.empty())
        {
            Node<T> *current = work_queue.pop();
            result.push(current->key_);
            if (current->left_)
            {
                work_queue.push(current->left_);
            }
            if (current->right_)
            {
                work_queue.push(current->right_);
            }
        }
        return result;
    }
    void Merge(Subset<T> &other)
    {
        if (!other.root_)
            return;
        if (!root_)
        {
            root_ = other.root_;
            size_ = other.size_;
            other.root_ = nullptr;
            other.size_ = 0;
            return;
        }
        root_ = MergeNodes(root_, other.root_);
        size_ = CountNodes(root_);
        other.root_ = nullptr;
        other.size_ = 0;
    }
    static Subset<T> MergeTrees(const Subset<T> &tree1, const Subset<T> &tree2)
    {
        Subset<T> result;
        for (auto it = tree1.begin(); it != tree1.end(); ++it)
            result.Insert(*it);
        for (auto it = tree2.begin(); it != tree2.end(); ++it)
            result.Insert(*it);
        return result;
    }
};