var isSubsequence = function(s, t) {
    if (s.length == 0) return true;
    let current = 0;
    for (let i = 0;i < t.length;i++) {
        if (t[i] == s[current]) current++;
    }
    return (current == s.length);
};