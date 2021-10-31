class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //for the first occurence using lower_bound approach
        auto first = lower_bound(nums.begin() , nums.end() , target);
        auto second = upper_bound(nums.begin() , nums.end() , target);
        int first1;
        if(first == nums.end() || first - nums.begin() == second - nums.begin())
            first1 = -1;
        else
        {
                first1 = first - nums.begin();
        }
        //finding the last occurence
        int s = 0 , e =nums.size()-1 , last = -1;
        while(s<e)
        {
            int m = (s+e)/2;
            if(nums[m] == target)
            {
                //check for the occurence in the right half
                last = m;
                s = m+1;
            }
            if(nums[m] > target)
            {
                e = m;
            }
            else
            {
                s = m +1;
            }
        }
        if(nums.size() == 1 && nums[0] == target)
            last = 0;
        if(nums.size()!= 0 && nums[s] == target)
            last = s;
        return {first1 , last};
    }
};