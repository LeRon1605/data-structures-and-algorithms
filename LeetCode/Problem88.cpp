#include <iostream>
#include <vector>
#include <iterator>
#include <map>
using namespace std;
class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            vector<int> result;
            for (int i = 0, i1 = 0, i2 = 0;i < n + m;i++) {
                if (i2 >= n || (i1 < m && nums1[i1] < nums2[i2])) {
                    result.push_back(nums1[i1]);
                    i1++;
                }else{
                    result.push_back(nums2[i2]);
                    i2++;
                }
            }
            nums1 = result;
        }
};
int main() {
    Solution solution;
    vector<int> arr1 = {};
    vector<int> arr2 = {-1, 4, 0};
    solution.merge(arr1, 0, arr2, 2);
    for (int i = 0;i < arr1.size();i++) {
        cout << arr1[i] << " ";
    }
}