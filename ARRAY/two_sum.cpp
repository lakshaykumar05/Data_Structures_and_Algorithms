class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        
        int i=0,j=nums.size()-1,s;
        vector<int> ans;
        int n=nums.size();
        vector<pair<int,int>> a(n);
        for(i=0;i<n;i++)
        {
            a[i].first=nums[i];
            a[i].second=i;
        }
        sort(a.begin(),a.end());
        i=0;
        while(i<j)
        {
            s=a[i].first+a[j].first;
            if(s==t)
            {
                ans.push_back(a[i].second);
                ans.push_back(a[j].second);
                return ans;
            }
            else if(s>t)
            {
                j--;
                
            }
            else
            {
                i++;
            }
        }
        ans.push_back(-1);
        return ans;
    }
};