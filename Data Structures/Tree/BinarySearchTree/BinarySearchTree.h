#include "./Node.h"
template <class T>
class BinarySearchTree {
    private:
        Node<T> *root;

    private:
        Node<T>* insertFunc(Node<T> *ptr, T value) {
            if (ptr == nullptr) {
                return new Node(value);
            } else if (ptr -> data < value) {
                ptr -> right = insertFunc(ptr -> right, value);
            } else {
                ptr -> left = insertFunc(ptr -> left, value);
            }
            return ptr;
        }

        void displayFunc(Node<T> *ptr) {
            if (ptr != nullptr) {
                displayFunc(ptr -> left);
                cout << ptr -> data << " ";
                displayFunc(ptr -> right);
            }
        }

    public:
        BinarySearchTree() {
            this -> root = nullptr;
        }

        BinarySearchTree(T value) {
            this -> root = new Node(value);
        }

        void insert(T value) {
            if (this -> root == nullptr) {
                this -> root = new Node(value);
            } else {
                // recursive way
                this -> insertFunc(this -> root, value);
                /*
                    // while loop way
                    Node<T> *ptr = this -> root;
                    while (ptr != nullptr) {
                        if (ptr -> data >= value) {
                            if (ptr -> left == nullptr) {
                                ptr -> left = new Node(value);
                                break;
                            } else {
                                ptr = ptr -> left;
                            }
                        } else {
                            if (ptr -> right == nullptr) {
                                ptr -> right = new Node(value);
                                break;
                            } else {
                                ptr = ptr -> right;
                            }
                        }
                    }
                */
            }
        }

        void remove(T value) {
            Node<T> *ptr = this -> root;
            Node<T> *parentNode = nullptr;
            while (ptr != nullptr) {
                if (ptr -> data > value) {
                    parentNode = ptr;
                    ptr = ptr -> left;
                } else if (ptr -> data < value) {
                    parentNode = ptr;
                    ptr = ptr -> right;
                } else {
                    // Node found, remove it!!
                    if (ptr -> left != nullptr && ptr -> right != nullptr) {
                        // Node has two child
                        if (ptr -> right -> left != nullptr) {
                            Node<T> *before = nullptr;
                            Node<T> *after = ptr -> right;
                            while (after -> left != nullptr) {
                                before = after;
                                after = after -> left;
                            }
                            before -> left = nullptr;
                            after -> left = ptr -> left;
                            after -> right = ptr -> right;
                            if (parentNode -> data > value) parentNode -> left = after;
                            else parentNode -> right = after;
                        } else {
                            ptr -> right -> left = ptr -> left;
                            if (parentNode -> data > value) parentNode -> left = ptr -> right;
                            else parentNode -> right = ptr -> right;
                        }
                    } else if (ptr -> left == nullptr && ptr -> right == nullptr) {
                        // leaf node
                        if (parentNode -> data > value) parentNode -> left = nullptr;
                        else parentNode -> right = nullptr;
                    } else if (ptr -> left != nullptr) {
                        // One left child
                        if (parentNode -> data > value) parentNode -> left = ptr -> left;
                        else parentNode -> right = ptr -> left;
                    } else if (ptr -> right != nullptr) {
                        // One right child
                        if (parentNode -> data > value) parentNode -> left = ptr -> right;
                        else parentNode -> right = ptr -> right;
                    }
                    break;
                }
            }
        }

        bool isExist(T value) {
            Node<T> *ptr = this -> root;
            while (ptr != nullptr) {
                if (ptr -> data == value) return true;
                else if (ptr -> data > value) ptr = ptr -> left;
                else ptr = ptr -> right;
            }
            return false;
        }

        void display() {
            displayFunc(this -> root);
            cout << endl;
        }
};