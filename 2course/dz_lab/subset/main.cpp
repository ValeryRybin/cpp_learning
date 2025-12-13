#include <iostream>
#include <cstdlib>
#include "Subset2.cpp"

void test_basic_operations()
{
    std::cout << "=== TEST 1: Basic Operations ===" << std::endl;
    Subset<int> tree;
    tree.Insert(10);
    tree.Insert(5);
    tree.Insert(15);
    tree.Insert(3);
    tree.Insert(7);
    tree.Insert(12);
    tree.Insert(20);
    std::cout << "Size: " << tree.Size() << std::endl;
    std::cout << "Height: " << tree.Height() << std::endl;
    std::cout << "Print tree:" << std::endl;
    tree.print_subset();
    std::cout << std::endl;
}

void test_dfs()
{
    std::cout << "=== TEST 2: DFS (In-order) ===" << std::endl;
    Subset<int> tree;
    tree.Insert(10);
    tree.Insert(5);
    tree.Insert(15);
    tree.Insert(3);
    tree.Insert(7);
    std::cout << "DFS order: ";
    Subvector<int> dfs_result = tree.DFS();
    for (unsigned int i = 0; i < dfs_result.size(); ++i)
    {
        std::cout << dfs_result[i] << " ";
    }
    std::cout << std::endl
              << std::endl;
}

void test_bfs()
{
    std::cout << "=== TEST 3: BFS (Level-order) ===" << std::endl;
    Subset<int> tree;
    tree.Insert(10);
    tree.Insert(5);
    tree.Insert(15);
    tree.Insert(3);
    tree.Insert(7);
    tree.Insert(12);
    tree.Insert(20);
    std::cout << "BFS order: ";
    Subqueue<int> bfs_result = tree.BFS();
    while (!bfs_result.empty())
    {
        std::cout << bfs_result.pop() << " ";
    }
    std::cout << std::endl
              << std::endl;
}

void test_find()
{
    std::cout << "=== TEST 4: Find ===" << std::endl;
    Subset<int> tree;
    tree.Insert(10);
    tree.Insert(5);
    tree.Insert(15);
    std::cout << "Find 5: " << (tree.Find(5) ? "Found" : "Not found") << std::endl;
    std::cout << "Find 20: " << (tree.Find(20) ? "Found" : "Not found") << std::endl;
    std::cout << std::endl;
}

void test_remove()
{
    std::cout << "=== TEST 5: Remove ===" << std::endl;
    Subset<int> tree;
    tree.Insert(10);
    tree.Insert(5);
    tree.Insert(15);
    tree.Insert(3);
    tree.Insert(7);
    tree.Insert(12);
    tree.Insert(20);
    std::cout << "Before remove - Size: " << tree.Size() << std::endl;
    tree.print_subset();
    std::cout << std::endl;
    tree.Remove(5);
    std::cout << "After remove 5 - Size: " << tree.Size() << std::endl;
    tree.print_subset();
    std::cout << std::endl
              << std::endl;
}

void test_merge()
{
    std::cout << "=== TEST 6: Merge (Efficient) ===" << std::endl;
    Subset<int> tree1;
    tree1.Insert(5);
    tree1.Insert(3);
    tree1.Insert(7);
    std::cout << "Tree1: ";
    tree1.print_subset();
    std::cout << std::endl;
    Subset<int> tree2;
    tree2.Insert(10);
    tree2.Insert(1);
    tree2.Insert(6);
    std::cout << "Tree2: ";
    tree2.print_subset();
    std::cout << std::endl;
    tree1.Merge(tree2);
    std::cout << "After merge - Tree1: ";
    tree1.print_subset();
    std::cout << std::endl;
    std::cout << "Tree2 size (should be 0): " << tree2.Size() << std::endl;
    std::cout << std::endl;
}

void test_merge_trees()
{
    std::cout << "=== TEST 7: MergeTrees (Static) ===" << std::endl;
    Subset<int> tree1;
    tree1.Insert(5);
    tree1.Insert(3);
    tree1.Insert(7);
    Subset<int> tree2;
    tree2.Insert(10);
    tree2.Insert(1);
    tree2.Insert(6);
    Subset<int> tree3 = Subset<int>::MergeTrees(tree1, tree2);
    std::cout << "Tree3 (merged): ";
    tree3.print_subset();
    std::cout << std::endl;
    std::cout << "Tree1 size (unchanged): " << tree1.Size() << std::endl;
    std::cout << "Tree2 size (unchanged): " << tree2.Size() << std::endl;
    std::cout << std::endl;
}

void test_iterator()
{
    std::cout << "=== TEST 8: Iterator ===" << std::endl;
    Subset<int> tree;
    tree.Insert(10);
    tree.Insert(5);
    tree.Insert(15);
    tree.Insert(3);
    tree.Insert(7);
    std::cout << "Iterate through tree: ";
    for (auto it = tree.begin(); it != tree.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl
              << std::endl;
}

void test_duplicates()
{
    std::cout << "=== TEST 9: Duplicates ===" << std::endl;
    Subset<int> tree;
    std::cout << "Insert 10: " << (tree.Insert(10) ? "Success" : "Failed") << std::endl;
    std::cout << "Insert 10 again: " << (tree.Insert(10) ? "Success" : "Failed (duplicate)") << std::endl;
    std::cout << "Size: " << tree.Size() << std::endl;
    std::cout << std::endl;
}

void test_large_tree()
{
    std::cout << "=== TEST 10: Large Tree ===" << std::endl;
    Subset<int> tree;
    for (int i = 1; i <= 20; i++)
    {
        tree.Insert(i * 3);
    }
    std::cout << "Inserted 20 elements" << std::endl;
    std::cout << "Size: " << tree.Size() << std::endl;
    std::cout << "Height: " << tree.Height() << std::endl;
    std::cout << "Tree structure:" << std::endl;
    tree.print_subset();
    std::cout << std::endl
              << std::endl;
}

int main()
{
    std::cout << "START TESTS" << std::endl;
    std::cout.flush();

    test_basic_operations();
    test_dfs();
    test_bfs();
    test_find();
    test_remove();
    test_merge();
    test_merge_trees();
    test_iterator();
    test_duplicates();
    test_large_tree();

    std::cout << "=== ALL TESTS COMPLETED ===" << std::endl;
    std::cout.flush();
    // system("pause");
    return 0;
}
