#include "./Stack_Array.h"
int main() {
    Stack<int> stack(5);
    stack.push(3);
    stack.push(4);
    cout << stack.pop();
    cout << stack.peak();
    cout << stack.pop();
    cout << stack.getLength();
}