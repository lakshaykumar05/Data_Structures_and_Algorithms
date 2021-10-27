/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> hash;//used unordered_map so that 
        //insertion takes O(1) time
        Node* ptr = head;
        while (ptr) {
            hash[ptr] =new Node(ptr->val);// storing the curr node's access
            ptr = ptr->next;
        }
        ptr = head;
        while (ptr) {
            hash[ptr]->next = hash[ptr->next];
            hash[ptr]->random = hash[ptr->random];
            ptr = ptr->next;
        }
        return hash[head];
        //Time Complexity = O(n)
        //Space Complexity = O(n)
    }
};