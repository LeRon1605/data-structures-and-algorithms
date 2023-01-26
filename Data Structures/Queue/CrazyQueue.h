#include "../Stack/Stack_LinkedList.h"
template <class T>
class CrazyQueue {
    private:
        Stack<T> left;
        Stack<T> right;
        T front;
    public:
        void enqueue(T value) {
            if (left.isEmpty() && right.isEmpty()) {
                front = value;
            }
            while (!left.isEmpty()) {
                right.push(left.pop());
            }
            right.push(value);
        }

        T dequeue() {
            while (!right.isEmpty()) {
                left.push(right.pop());
            }
            T value = left.pop();
            front = left.peak();
            return value;
        }

        T peak() {
            return this -> front;
        }

        bool isEmpty() {
            return (left.isEmpty() && right.isEmpty());
        }
};