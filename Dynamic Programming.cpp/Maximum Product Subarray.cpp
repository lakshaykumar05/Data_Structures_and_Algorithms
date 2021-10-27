class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size() , res_p = nums[0] , res_n =  nums[0] , res = nums[0] , res_1 = nums[0];
        for(int i = 1  ; i < n ; i++)
        {
            if(nums[i] < 0)
            {
                swap(res_p , res_n);
            }
            res_p = max(nums[i] * res_p , nums[i]);
            res_n = min(nums[i] * res_n , nums[i]);
            res = max(res_p , res);
            res_1 = min(res_1 , res_n);
        }
        cout<<res<<" "<<res_1;
        //res_1 is min product of and res is the max product
        return res;
    }
};