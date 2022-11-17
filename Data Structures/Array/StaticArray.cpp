#include <iostream>
using namespace std;
void push(int arr[], int &n, int value) {
    arr[n] = value;
    n++;
}
void insert(int arr[], int &n, int index, int value) {
    for (int i = n;i > index;i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    n++;
}
void remove(int arr[], int &n, int index) {
    for (int i = index;i < n - 1;i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}
int search(int arr[], int n, int value) {
    for (int i = 0;i < n;i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}
void print(int arr[], int n) {
    for (int i = 0;i < n;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    // store sequence of number in memory
    int n = 4;
    int arr[10] = {1, 2, 3, 4};

    // access: O(1)
    int value = arr[1];

    cout << "Array: ";
    print(arr, n);

    // push: O(1)
    push(arr, n, 5);
    cout << "After push: "; 
    print(arr, n);

    // insert: O(n)
    insert(arr, n, 2, 6);
    cout << "After insert: "; 
    print(arr, n);

    // remove: O(n)
    remove(arr, n, 2);
    cout << "After remove: "; 
    print(arr, n);

    // search: O(n)
    cout << "Search index: " << search(arr, n, 5);
    return 0;
}