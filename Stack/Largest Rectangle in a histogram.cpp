class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        //next smaller element and previous smaller elemnt approach
        stack<int>st;
        int n = nums.size();
        vector<int>left_smaller(n , -1) , right_smaller(n , -1);
        for(int i = 0 ; i < n ;  i++)
        {

            while(!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }
            if(st.size()==0)
                left_smaller[i] = 0;
            else
                left_smaller[i] = st.top()+1;
            st.push(i);
            
        }
        while(!st.empty()) st.pop();
        for(int i = n-1 ; i >=0 ; i--)
        {
            while(!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }
            if(st.size() ==0)
                right_smaller[i] = n-1;
            else
                right_smaller[i] = st.top()-1;
            st.push(i);
        }
        int res = 0 ;
        for(int i =0 ;i < n ; i++)
        {
            res = max(res , (right_smaller[i] -left_smaller[i] +1) * nums[i]);
        }
        return res;
        
    }
};