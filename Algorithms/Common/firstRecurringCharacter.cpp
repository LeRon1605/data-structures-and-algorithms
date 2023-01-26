#include <iostream>
#include <iterator>
#include <map>
using namespace std;

int firstReccurringCharacter1(int arr[], int n) {
    for (int i = 0;i < n;i++) {
        for (int j = i + 1;j < n;j++) {
            if (arr[i] == arr[j]) return arr[i];
        }
    }
    // Time Complexity: O(n^2)
    // Space Complexity: O(1)
    return -1;
}

int firstRecurringCharacter2(int arr[], int n) {
    map<int, int> repo;
    for (int i = 0;i < n;i++) {
        if (repo.find(arr[i]) != repo.end()) return arr[i];
        repo.insert({arr[i], arr[i]});
    }
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 2, 5, 3};
    int n = 6;
    cout << firstReccurringCharacter1(arr, n);
    cout << firstRecurringCharacter2(arr, n);
}