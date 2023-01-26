var containsNearbyDuplicate = function(nums, k) {
    let frequency = {}
    for (let i = 0;i < nums.length;i++) {
        let key = nums[i].toString();
        if (frequency[key] != undefined) {
            if (i - frequency[key] <= k)
                return true;
        }
        frequency[key] = i;
    }
    return false;
};