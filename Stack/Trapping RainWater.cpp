class Solution {
public:
    //optimized 2 ptr solution
    int trap(vector<int>& a) {
        int n = a.size();
        int l_max = 0 , r_max = 0;
        int l = 0 , r = n-1 , res =0;
        while(l<=r)
        {
            if(a[l] <= a[r])
            {
                if(a[l] >= l_max)
                    l_max = a[l];
                else
                    res+=(l_max - a[l]);
                l++;
            }
            else
            {
                if(a[r]>= r_max)
                    r_max = a[r];
                else
                    res+=(r_max - a[r]);
                r--;
            }
        }
        return res;
    }
};