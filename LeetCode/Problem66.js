var plusOne = function(digits) {
    let result = [];
    let remainder = 1;
    for (let i = digits.length - 1;i >= 0;i--) {
        if (remainder > 0) {
            if (digits[i] + remainder >= 10) {
                remainder = (digits[i] + remainder) % 9;
                result.unshift(0);
            } else {
                result.unshift(digits[i] + remainder);
                remainder = 0;
            }
        } else {
            result.unshift(digits[i]);
        }
    }
    if (remainder != 0) result.unshift(remainder);
    return result;
};