class Solution {
public:
    vector <int> dp ; 
    int fun(vector<int> nums , int n )
    {
        int g =0 ;
        for(int i = 0 ; i<n ; i++)
        {
            int c =0 ;
            
            for(int j =0 ; j <i ; j++)
            {
                if(nums[j] < nums[i])
                {
                    if(dp[j] >c)
                        c = dp[j];
                }
            }
            if((c+1) > g)
                g = c+1;
            dp.push_back(c+1);
        }
        
        for(auto i : dp)
        {
            cout<<i<<"\n";
        }
        return g;
    }
    int lengthOfLIS(vector<int>& nums) {
        return fun(nums , nums.size());
    }
};