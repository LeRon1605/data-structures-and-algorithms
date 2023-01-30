var maxSubArray = function(nums) {
    let temp = nums[0], result = nums[0];
    for (let i = 1;i < nums.length;i++) {
        temp = temp + nums[i] > nums[i] ? temp + nums[i] : nums[i];
        if (temp > result) {
            result = temp;
        }
    }
    return result;
};