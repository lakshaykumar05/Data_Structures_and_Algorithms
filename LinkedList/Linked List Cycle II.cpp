class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)
            return NULL;
        ListNode*slow = head;
        ListNode*fast = head;
        if(!head->next)
            return head->next;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast)
                break;
        }
        if(slow!=fast)
            return NULL;
        slow = head;
        while(slow!=fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};