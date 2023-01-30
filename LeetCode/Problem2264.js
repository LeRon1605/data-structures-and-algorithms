var largestGoodInteger = function(num) {
    let result = "";
    for (let i = 0;i < num.length - 2;i++) {
        if (num[i] == num[i + 1] && num[i + 1] == num[i + 2] && (result == "" || result[0] < num[i])) {
            result = num[i] + num[i + 1] + num[i + 2];
        }
    }
    return result;
};