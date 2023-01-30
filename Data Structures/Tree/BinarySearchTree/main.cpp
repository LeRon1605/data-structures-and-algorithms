#include "./BinarySearchTree.h"
int main() {
    BinarySearchTree<int> tree;
    tree.insert(1);
    tree.insert(0);
    tree.insert(3);
    // tree.insert(5);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.display();
    // cout << tree.isExist(1);
    // cout << tree.isExist(4);
    // tree.remove(4);
    tree.remove(3);
    tree.display();
}