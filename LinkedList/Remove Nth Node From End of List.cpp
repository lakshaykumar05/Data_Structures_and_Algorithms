class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i = 0 ; i < n ; i++)
        {
            if( fast )
            {
                fast = fast->next;                
            }
            else
                return head;
        }
        ListNode*temp;
        while(fast)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if(slow==head)
        {
            head = head->next;
            return head;
        }
        cout<<slow->val <<" ";
        temp->next = slow->next;
        return head;
        
    }
};