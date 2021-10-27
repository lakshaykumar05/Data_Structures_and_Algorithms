class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int m = nums.size();
        int n = nums[0].size();
        int i = 0 , j = n-1;
        while(i >=0 && i < m && j >=0 && j < n)
        {
            if(nums[i][j] == target)
                return true;
            else
            {
                if(nums[i][j] > target)       
                {
                    j--;
                }
                else
                if(nums[i][j] < target)
                {
                    i++;
                }
            }
        }
        return false;
    }
};