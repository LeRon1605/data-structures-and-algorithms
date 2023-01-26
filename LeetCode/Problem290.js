var wordPattern = function(pattern, s) {
    let arr = s.split(' ');
    let mapper = {};
    if (arr.length != pattern.length) return false;
    for (let i = 0;i < pattern.length;i++) {
        let keyP = 'keyP' + pattern[i];
        let keyA = 'keyA' + arr[i];
        if (!mapper[keyP]) {
            mapper[keyP] = arr[i];
        }
        if (!mapper[keyA]) {
            mapper[keyA] = pattern[i];
        }
        if (mapper[keyA] != pattern[i] || mapper[keyP] != arr[i]) return false;
    }
    return true;
};