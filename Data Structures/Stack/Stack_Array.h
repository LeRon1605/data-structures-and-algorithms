#include <iostream>
using namespace std;
template <class T>
class Stack {
    private:
        int size;
        int top;
        T *data;
    public:
        Stack(int size) {
            this -> size = size;
            this -> data = new T[size];
            this -> top = -1;
        }

        void push(T value) {
            if (top < size) {                
                this -> top += 1;
                this -> data[this -> top] = value;
            } else {
                throw "Stack overflow";
            }
        }

        T peak() {
            if (this -> top >= 0) {
                return this -> data[this -> top];
            }
            throw "Empty stack";
        }

        T pop() {
            if (this -> top >= 0) {
                return this -> data[this -> top--];
            }
            throw "Empty stack";
        }

        bool isEmpty() {
            return (this -> top == -1);
        }

        int getLength() {
            return this -> top + 1;
        }
};