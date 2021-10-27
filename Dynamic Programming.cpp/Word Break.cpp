class Solution {
public:
    //memoization based approach
    set<int>st;//possibilities
    bool fun(string s , vector<string>w , int pos , vector<int>&dp)
    {
        //base cond
        if(pos>=s.size())
        {
            return dp[pos] = 1;
        }
        if(dp[pos]!=-1)
            return dp[pos];
        //possible recursion calls
        for(auto i : st)
        {
            string s1 = s.substr(pos,i);
            if(find(w.begin(), w.end(),s1)!=w.end() && fun(s,w,pos+i, dp))
            {   
                cout<<s1<<" ";
                return dp[pos] =1;
            }
        }
        return dp[pos] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto i : wordDict)
        {
            st.insert(i.size());
        }
        vector<int>dp(s.size() +1 , -1);
        return fun(s, wordDict , 0 , dp);
        
    }
};
