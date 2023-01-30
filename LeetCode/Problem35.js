// O(n)
var searchInsert = function(nums, target) {
    if (target <= nums[0]) return 0;
    if (target > nums[nums.length - 1]) return nums.length;
    for (let i = 1;i < nums.length;i++) {
        if (target >= nums[i - 1] && target <= nums[i]) return i;
    }
};

// O(log n): Binary search
var searchInsert = function(nums, target) {
    if (target <= nums[0]) return 0;
    if (target > nums[nums.length - 1]) return nums.length;
    let left = 0, right = nums.length - 1;
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return left;
};