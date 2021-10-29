class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty() || lists.size() == 0)
        {
            return NULL;
        }
        auto comp = [&](ListNode* a , ListNode *b)
        {
            if(a->val > b->val)
                return true;
            return false;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(comp)>pq(comp);

        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i])
            {
                pq.push(lists[i]);
            }
        }
        ListNode dummyHead(0);
        ListNode *tail = &dummyHead;
        while (!pq.empty())
        {
            // Pop the top element and store it in temp
            auto temp = pq.top();
            pq.pop();

            // Add it to the list
            tail->next = temp;
            // Move the tail to the newly added element
            tail = tail->next;
            // if there are more nodes attached to this node in the list
            // Push the next node of the list into the heap
            if (temp->next)
            {
                pq.push(temp->next);
            }
        }
        tail->next = NULL;
        return dummyHead.next;
    }
};