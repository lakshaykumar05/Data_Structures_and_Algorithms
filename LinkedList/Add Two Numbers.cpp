/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0 ;
        ListNode* temp = new ListNode((l1->val + l2->val)%10);
        ListNode* p = temp;
        carry = (l1->val + l2->val)/10;
        l1 = l1->next;
        l2 = l2->next;
        cout<<carry<<" ";
        while(l1 && l2)
        {
            int sum = l1->val + l2->val;
            sum+=carry;
            carry = sum/10;
            cout<<sum<<" ";
            ListNode* temp1 = new ListNode(sum%10);
            p->next = temp1;
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1)
        {
            ListNode* temp1 = new ListNode((l1->val + carry)%10);
            carry = (l1->val + carry)/10;
            p->next = temp1;
            p = p->next;
            l1= l1->next;
        }
        while(l2)
        {
            ListNode* temp1 = new ListNode((l2->val + carry)%10);
            carry = (l2->val + carry)/10;
            p->next = temp1;
            p = p->next;
            l2 = l2->next;
        }
        if(carry)
        {
            ListNode*temp1  = new ListNode(carry);
            p->next = temp1;
        }
        return temp;
    }
};