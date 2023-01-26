var frequencySort = function(s) {
    s = s.split('');
    let obj = {};
    let result = '';
    for (let i = 0;i < s.length;i++) {
        if (!obj[s[i]]) obj[s[i]] = 1;
        else obj[s[i]]++;
    }
    const key = Object.keys(obj);
    for (let i = 0;i < key.length;i++) {
        let max = 0;
        for (let j = 0;j < key.length;j++) {
            if (obj[key[j]] > obj[key[max]]) max = j;
        }
        result += key[max].repeat(obj[key[max]]);
        obj[key[max]] = 0;
    }
    return result;
};