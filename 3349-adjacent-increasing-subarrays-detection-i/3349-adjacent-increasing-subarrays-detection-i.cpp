class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int prevrun=0,currrun=1;
        int ans=0;
      
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                currrun++;
            }else {
                prevrun=currrun;
                currrun=1;
            }
            ans=max({ans,currrun/2,min(prevrun,currrun)});
            if(ans>=k)
            return true;
        }
    return false;}
};