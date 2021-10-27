class Solution {
public:
    //tabulation
    int fun(int n , vector<int>dp)
    {        
        dp[1] = 1;
        dp[2] = 2;
        for(auto i = 3 ; i <=n ; i++)
        {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n]       ;
    }
    int climbStairs(int n) {
        vector<int>dp(46 , -1);         
        return fun(n , dp);
    }
};