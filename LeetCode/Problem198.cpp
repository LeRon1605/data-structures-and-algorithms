#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public: 
        void rotate(vector<int>& nums, int k) {
            k %= nums.size();
            if (k != 0 && k != nums.size() && k < nums.size()) {
                vector<int> temp;
                for (int i = 0;i < k;i++) {
                    int value = nums[nums.size() - k + i];
                    if (i + k < nums.size()) {
                        temp.push_back(nums[i + k]);
                        nums[i + k] = nums[i];
                    }
                    nums[i] = value;
                }
                if (k > nums.size() / 2) {
                    for (int i = k - 1, j = 0;j < temp.size();k--, i++, j++) {
                        nums[i] = temp[j];
                    }
                }else{
                    for (int i = 2 * k, j = 0;i < nums.size();i++, j++) {
                        nums[i] = temp[j];
                    }
                }
            }
        }
};
int main() {
    Solution solution;
    vector<int> input = {-1, -100, 3, 99};
    solution.rotate(input, 3);
    for (int i = 0;i < input.size();i++) {
        cout << input[i] << " ";
    }
}