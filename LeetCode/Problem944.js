var minDeletionSize = function(strs) {
    let count = 0;
    for (let i = 0;i < strs[0].length;i++) {
        for (let j = 1;j < strs.length;j++) {
            if (strs[j][i] < strs[j - 1][i]) {
                count++;
                break;
            }
        }
    }
    return count;
};