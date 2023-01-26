#include "./CrazyQueue.h"
int main() {
    CrazyQueue<string> waitList;
    waitList.enqueue("Ron");
    waitList.enqueue("Ron1");
    waitList.enqueue("Ron2");
    cout << waitList.dequeue();
    cout << waitList.peak();
    cout << waitList.dequeue();
}