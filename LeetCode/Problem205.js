var isIsomorphic = function(s, t) {
    let obj = {};
    for (let i = 0;i < s.length;i++) {
        if (obj[t[i]] != undefined) {
            if (obj[t[i]] != s[i]) return false;
        } else {           
            if (Object.values(obj).some(x => x == s[i])) return false; 
            obj[t[i]] = s[i];
        }
    }
    return true;
};