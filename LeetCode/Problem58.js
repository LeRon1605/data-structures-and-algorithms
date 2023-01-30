var lengthOfLastWord = function(s) {
    let isCount = false;
    let count = 0;
    for (let i = s.length - 1;i >= 0;i--) {
        if (s[i] != ' ') isCount = true;
        if (isCount) {
            if (s[i] != ' ') count++;
            else return count;
        }
    }
    return count;
};