class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int val=0;
        for(int x:nums){
             int idx=abs(x);
             if(nums[idx]<0)
                return idx;
             else
                nums[idx]=-nums[idx];        
        }
        
        return val;
    }
};