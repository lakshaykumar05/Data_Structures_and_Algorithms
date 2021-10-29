class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k ==1)
            return head;
        ListNode* temp = new ListNode(0);
        temp -> next = head;
        ListNode*curr = temp , *nex = temp , *pre  = temp;
        int len = 0 ;
        while(curr)
        {
            len++;
            curr = curr->next;
        }
        while(len >k)
        {
            curr = pre->next;
            nex = curr -> next;
            for(int i = 1 ; i < k ; i++)
            {
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            pre = curr;
            len-=k;
        }
        return temp->next;
    }
};