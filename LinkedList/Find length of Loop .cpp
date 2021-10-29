int countNodesinLoop(struct Node *head)
{
    Node *fast = head , *slow = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }
    if(slow!= fast)//no loop detected
        return 0;
    slow = head;
    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
        
    }
    //point of intersection is in slow
    Node* temp = slow->next;
    int res = 0;
    while(slow != temp)
    {
        temp = temp->next;
        res++;
    }
    return res+1;    
    // Code here
}