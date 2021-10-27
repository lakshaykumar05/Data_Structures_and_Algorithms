class Solution {
public:
    int dp[1001][1001];
    int longestPalindromeSubseq(string s) {
        //lcs b/w s and reverse of s
        string s1 = s;
        reverse(s.begin() , s.end());
        
        for(int i = 0 ; i < s.size() ; i++)
        {
            dp[i][0] = 0;
            dp[0][i] = 0;
        }
        for(int i = 1 ;i <= s1.size() ; i++)
        {
            for(int j = 1 ; j <=s.size() ; j++)
            {
                if(s1[i-1] == s[j-1])
                {
                    dp[i][j] = 1+ dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] =  max(dp[i-1][j],dp[i][j-1]);  
                }
            }
        }
        return dp[s.size()][s.size()];
    }
};