class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto v:mp){
            if(v.second>nums.size()/2){
                return v.first;
            }
        }
        return -1;
    }
};