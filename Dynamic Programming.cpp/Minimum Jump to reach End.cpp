class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int dp[10000];
        dp[n-1] = 0;
        for(int i = n-2 ;i >=0 ; i--)
        {
            int min = INT_MAX;
            if(nums[i] == 0)
                dp[i] = -1;
            else   
            {
                for(int j = 1 ;j <= nums[i] && j + i < n ; j++)
                {
                    if(dp[i+j]!=-1 && dp[i+j] < min)
                    {
                        min = dp[i+j];
                    }
                }   
                if(min!=INT_MAX)
                    dp[i] = min+1;
                else
                    dp[i]=-1;
            }
        }
        for(int i = 0 ; i < n ; i++)
            cout<<dp[i]<<" ";
        return dp[0];
        
    }
};