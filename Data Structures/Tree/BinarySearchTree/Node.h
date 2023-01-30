#include <iostream>
using namespace std;
template <class T>
class Node {
    public:
        T data;
        Node *left;
        Node *right;
        
        Node(T data) {
            this -> data = data;
            this -> left = nullptr;
            this -> right = nullptr;
        }
        Node(T data, Node *left, Node *right) {
            this -> data = data;
            this -> left = left;
            this -> right = right;
        }
};