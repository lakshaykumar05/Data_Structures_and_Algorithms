class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        vector<pair<int,int>> vp(nums.size());
        for(int i=0;i<nums.size();i++){
            vp[i].first=nums[i];
            vp[i].second=i;
        }
        sort(vp.begin(),vp.end());
        vector<int> ans;
        while(i<j){
            if(vp[i].first+vp[j].first<target){
                i++;
            }
            else if(vp[i].first+vp[j].first>target){
                j--;
            }
            else if(vp[i].first+vp[j].first==target){
                ans.push_back(vp[i].second);
                ans.push_back(vp[j].second);
                break;
            }
        }
        return ans;
    }
};