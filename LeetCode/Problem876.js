var middleNode = function(head) {
    let before = head;
    let after = head;
    while (after != null && after.next != null) {
        before = before.next;
        after = after.next.next;
    }
    return before;
};

var middleNode = function(head) {
    let p = head;
    let count = 0;
    while (p != null) {
        p = p.next;
        count++;
    }
    p = head;
    for (let i = 0;i < Math.floor(count / 2);i++) {
        p = p.next;
    }
    return p;
};