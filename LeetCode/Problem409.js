var longestPalindrome = function(s) {
    let obj = {};
    let result = 0;
    for (let i = 0;i < s.length;i++) {
        if (obj[s[i]] == undefined) {
            obj[s[i]] = 1;
        } else {
            result += 2;
            delete obj[s[i]];
        }
    }
    return Object.keys(obj).length === 0 ? result : result + 1;
};