class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0 , len2= 0;
        ListNode*temp = headA ;
        ListNode*temp1 = headB;
        while(temp)
        {
            len1++;
            temp = temp->next;
        }
        while(temp1)
        {
            len2++;
            temp1= temp1->next;
        }
        int left = abs(len1 - len2);
        temp = headA;
        temp1 = headB;
        if(len2 > len1)
        {
            swap(temp , temp1);
        }
        while(left)
        {
            temp = temp->next;
            left--;
        }
        while(temp!=temp1)
        {
            temp = temp->next;
            temp1= temp1->next;
        }
        return temp;
    }
};