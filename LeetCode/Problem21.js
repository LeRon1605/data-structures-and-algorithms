var mergeTwoLists = function(list1, list2) {
    if (!list1) return list2;
    while (list2 && list1.val > list2.val) {
        list1 = new ListNode(list2.val, list1);
        list2 = list2.next;
    }
    let ptr = list1;
    while (list2 && ptr) {
        while (ptr.next != null && !(ptr.next.val >= list2.val && ptr.val <= list2.val)) ptr = ptr.next;
        ptr.next = new ListNode(list2.val, ptr.next);
        ptr = ptr.next;
        list2 = list2.next;
    }
    return list1;
};