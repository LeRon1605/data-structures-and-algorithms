#include <iostream>
#include "./Node.h"
using namespace std;
template <class T>
class Queue {
    private:
        int length;
        Node<T> *head;
        Node<T> *tail;
    public:
        Queue() {
            this -> length = 0;
            this -> head = nullptr;
            this -> tail = nullptr;
        }

        void enqueue(T value) {
            Node<T> *node = new Node(value);
            if (this -> head == nullptr) {
                this -> head = node;
                this -> tail = node;
            } else {
                this -> tail -> next = node;
                this -> tail = node;
            }
            this -> length += 1;
        }

        T peak() {
            if (this -> head != nullptr) {
                return this -> head -> data;
            }
            throw "Empty Queue";
        }

        T dequeue() {
            if (this -> head != nullptr) {
                if (this -> head == this -> tail) {
                    this -> tail = nullptr;
                }
                T value = this -> head -> data;
                Node<T> *temp = this -> head;
                this -> head = this -> head -> next;
                delete temp;
                this -> length -= 1;
                return value;
            }
            throw "Empty queue";
        }

        bool isEmpty() {
            return (this -> head == nullptr);
        }

        int getLength() {
            return this -> length;
        }
};