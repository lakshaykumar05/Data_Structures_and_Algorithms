class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0,val=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
            }
            if( nums[i]==0 or i==nums.size()-1 ){
                val=max(val,count);
                count=0;
            }
        }
        return val;
    }
};