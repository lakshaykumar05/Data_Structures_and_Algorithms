class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0,val=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
            }
            else if(nums[i-1]==1 and nums[i]==0 ){
                val=max(val,count);
                count=0;
            }
        }
    }
};