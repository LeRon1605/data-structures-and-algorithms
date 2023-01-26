var halvesAreAlike = function(s) {
    let countA = 0, countB = 0;
    let vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'];
    for (let i = 0;i < s.length;i++) {
        if (i >= s.length / 2) {
            if (vowels.some(x => x == s[i])) countB++;
            if (countB > countA) return false;
        } else {
            if (vowels.some(x => x == s[i])) countA++;
        }
    }
    return (countA == countB);
};