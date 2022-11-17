#include <iostream>
#include <vector>
#include <iterator>
#include <set>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> data;
        for (int i = 0;i < nums.size();i++) {
            if (data.find(nums[i]) != data.end()) {
                return true;
            }else{
                data.insert(nums[i]);
            }
        }      
        return false;
    }
};
int main() {
    Solution solution;
    vector<int> arr = {1, 2, 3, 4};
    cout << solution.containsDuplicate(arr);
}