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
    void reorderList(ListNode* head) {
        stack<ListNode*>st;
        ListNode*temp = head;
        int n = 0;
        while(temp)
        {
            st.push(temp);
            temp = temp->next;
            ++n;
        }
        temp = head;
        for(int i = 0 ; i < n/2 ; i++)
        {
            ListNode*c = temp->next;
            temp->next = st.top();
            st.top()->next = c;
            temp = temp->next->next;
            st.pop();
            
        }
        temp->next = nullptr;
    }
};