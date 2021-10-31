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
    ListNode* middleNode(ListNode* head) {
        ListNode* len=head;
        int count=0;
        while(len!=NULL){
            count++;
            len=len->next;
        }
        int put=count/2;
        int i=0;
        while(i<put){
            head=head->next;
            i++;
        }
           return head;
        
    }
 
};
