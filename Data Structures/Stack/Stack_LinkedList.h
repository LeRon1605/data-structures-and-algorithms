#include <iostream>
#include "./Node.h"
using namespace std;
template <class T>
class Stack {
    private:
        int length;
        Node<T> *head;
    public:
        Stack() {
            this -> length = 0;
            this -> head = nullptr;
        }

        void push(T value) {
            Node<T> *node = new Node(value);
            if (this -> head == nullptr) {
                this -> head = node;
            } else {
                node -> next = this -> head;
                this -> head = node;
            }
            this -> length += 1;
        }

        T peak() {
            if (this -> head != nullptr) {
                return this -> head -> data;
            }
            throw "Empty stack";
        }

        T pop() {
            if (this -> head != nullptr) {
                T value = this -> head -> data;
                Node<T> *temp = this -> head;
                this -> head = this -> head -> next;
                delete temp;
                this -> length -= 1;
                return value;
            }
            throw "Empty stack";
        }

        bool isEmpty() {
            return (this -> head == nullptr);
        }

        int getLength() {
            return this -> length;
        }
};