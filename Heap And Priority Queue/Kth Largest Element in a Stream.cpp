class KthLargest {
public:
    int curr_k;
    priority_queue<int,vector<int>,greater<int>> minheap;
    KthLargest(int k, vector<int>& nums) {
        curr_k=k;
        for(int x:nums)
            add(x);
    }
    int add(int val) {
        if(minheap.size()<curr_k)
            minheap.push(val);
        else
        {
            if(val>minheap.top())
            {
                minheap.pop();
                minheap.push(val);
            }
        }
        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */