class Solution {
public:
    int bs(vector <int> arr ,  int l, int r, int x)
    {
        if (r >= l) {
            int mid = l + (r - l) / 2;

            if (arr[mid] == x)
                return mid;

            if (arr[mid] > x)
                return bs(arr, l, mid - 1, x);

            return bs(arr, mid + 1, r, x);
        }

        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        // search for the min ele
        if(n==1 )
        {
            if(nums[0] == target)
                return 0;
            else
                return -1;
        }
            
        int res = 0  , max = n-1;
        if(nums[res] > nums[max])
        {
            for(int i =0 ; i < n-1 ; i++)
            {
                if(nums[i+1]< nums[i])
                {
                    res = i+1 ; 
                    max = i;
                    break;
                }
            }
        }
        if(target == nums[res])
            return res;
        if(target == nums[max] )       
            return max;
        if(target < nums[0])
        {
            // apply binary search between res and n-1;
            return bs(nums , res , n-1 , target);
        }
        else
        {
            // apply binary search between index 0 and max;
            return bs(nums , 0 , max , target);
            
        }
            
        
    }
};