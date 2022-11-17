#include <iostream>
#include <vector>
#include <iterator>
#include <map>
using namespace std;
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> result;
            map<int, int> data;
            for (int i = 0;i < nums.size();i++) {
                auto key = data.find(target - nums[i]);
                if (key != data.end()) {
                    result.push_back(key -> second);
                    result.push_back(i);
                    return result;
                }else{
                    data.insert({nums[i], i});
                }
            }
            return result;
        }
};
int main() {
    Solution solution;
    vector<int> input = {1, 2, 3};
    auto result = solution.twoSum(input, 5);
    cout << result[0] << " " << result[1];
}