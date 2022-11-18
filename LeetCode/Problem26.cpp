// Remove Duplicates from Sorted Array
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1;
        int n = nums.size();
        for (int i = 1;i < n;i++) {
            if (nums[i] != nums[j - 1]) {
                nums[j++] = nums[i];
                if (nums[i] == nums[n - 1]) break;
            }
        }
        return j;
    }
};