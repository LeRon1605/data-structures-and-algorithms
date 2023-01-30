var pivotIndex = function(nums) {
    let sum = nums.reduce((res, e) => res + e);
    if (sum - nums[0] == 0) return 0;
    let leftSum = nums[0];
    for (let i = 1;i < nums.length;i++) {
        if (sum - leftSum - nums[i] == leftSum) return i;
        leftSum += nums[i];
    }
    return -1;
};