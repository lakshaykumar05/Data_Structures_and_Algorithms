class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        int n=a.size(),i=0,ans=INT_MIN,o;
        for(i=0;i<n;i++)
        {
            o=0;
            while(i<n && a[i]==1)
            {
                o++;
                i++;
            }
            ans=max(ans,o);
        }
        return ans;
    }
};