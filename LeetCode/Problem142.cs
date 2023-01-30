public class Solution {
    public ListNode DetectCycle(ListNode head) {
        IDictionary<ListNode, bool> repo = new Dictionary<ListNode, bool>();
        ListNode ptr = head;
        while (ptr != null) {
            if (repo.ContainsKey(ptr)) {
                return ptr;
            } else {
                repo[ptr] = true;
            }
            ptr = ptr.next;
        }
        return null;
    }
}