class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode*fast = head;
        ListNode*slow = head;
        if(!head)
            return nullptr;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};