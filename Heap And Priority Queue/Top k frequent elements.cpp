class Solution {
public:
    //hashmap approach
    vector<int>hash_fun(vector<int>&nums , int k)
    {
        unordered_map<int , int>hash;
        auto comp = [&](pair<int , int>a , pair<int , int>b){
                if(a.second>b.second)
                    return true;
            return false;
        };
        for(int num : nums)
        {
            hash[num]++;
        }
        vector<pair<int , int>>a;
        for(auto i : hash)
        {
            a.push_back({i.first , i.second});
        }
        sort(a.begin() , a.end() , comp);
        vector<int> ans;
        for(auto i : a)
        {
            if(k!=0)
            {
                ans.push_back(i.first);
                k--;
            }
        }
        return ans;
    }
    //priority queue + hashmap approach
    vector<int>heap_fun(vector<int>&nums , int k)
    {
        vector<int> v;
        unordered_map<int, int> hash;
        for(auto n: nums) 
            hash[n]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> q;//min heap
        for(auto& pair: hash) 
        {
            q.push({pair.second, pair.first});
            if(q.size() > k) 
                q.pop();
        }
        while(k--)
        {
            v.push_back(q.top().second);
            q.pop();
        }
        return v;
    }
            
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // return hash_fun(nums , k);
        return heap_fun(nums , k);
    }
};