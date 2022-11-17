#include <iostream>
using namespace std;
int* mergeSortedArray(int firstArr[], int secondArr[], int n, int m) {
    int *result = new int[n + m];
    int iFirst = 0, iSecond = 0;
    for (int i = 0;i < n + m;i++) {
        if ((iSecond >= m || firstArr[iFirst] < secondArr[iSecond])) {
            // if iSecond >= m means it's already merged so we dont care about secondArr anymore
            result[i] = firstArr[iFirst];
            iFirst++;
        } else {
            result[i] = secondArr[iSecond];
            iSecond++;
        }
    }
    return result;
}
void print(int *arr, int n) {
    for (int i = 0;i < n;i++) {
        cout << arr[i] << " ";
    }
}
int main() {
    int firstArr[] = {1, 7};
    int secondArr[] = {3, 5, 90};
    int n = sizeof(firstArr) / sizeof(int);
    int m = sizeof(secondArr) / sizeof(int);
    int *result = mergeSortedArray(firstArr, secondArr, n, m);
    print(result, n + m);
}