var isValid = function(s) {
    let stack = [];
    for (let i = 0;i < s.length;i++) {
        if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            let c = stack.pop() + s[i];
            if (c != '()' && c != '{}' && c != '[]') return false;
        } else if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack.push(s[i]);
        }
    }
    return (stack.length == 0);
};