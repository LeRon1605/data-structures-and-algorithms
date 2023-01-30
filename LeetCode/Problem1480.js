var runningSum = function(nums) {
    let accumulator = nums[0];
    for (let i = 1;i < nums.length;i++) {
        accumulator += nums[i];
        nums[i] = accumulator;
    }
    return nums;
};