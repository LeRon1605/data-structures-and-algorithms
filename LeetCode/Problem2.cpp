/*
    You are given two non-empty linked lists representing two non-negative integers. 
    The digits are stored in reverse order, and each of their nodes contains a single digit. 
    Add the two numbers and return the sum as a linked list.

    Link: https://leetcode.com/problems/add-two-numbers/
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode *result = new ListNode();
            ListNode *ptr = result;
            int remember = 0;
            while (l1 != nullptr || l2 != nullptr) {
                int value = 0;
                if (l1 == nullptr) {
                    value = l2 -> val;
                    l2 = l2 -> next;
                }else if (l2 == nullptr) {
                    value = l1 -> val;
                    l1 = l1 -> next;
                }else{
                    value = l1 -> val + l2 -> val;
                    l1 = l1 -> next;
                    l2 = l2 -> next;
                }
                int sum = value + remember;
                if (sum > 9) {
                    remember = sum / 10;
                    sum = sum % 10;
                }else{
                    remember = 0;
                }
                ptr -> val = sum;
                if (l1 != nullptr || l2 != nullptr)
                {
                    ptr -> next = new ListNode();
                    ptr = ptr -> next;
                }
            }
            if (remember > 0) {
                ptr -> next = new ListNode(remember);
            }
            return result;
        }
};