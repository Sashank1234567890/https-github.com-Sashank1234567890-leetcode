class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int rem=0;
        vector<bool>ans(nums.size());
        for(int i=0;i<nums.size();i++){
              rem=(rem*2+nums[i])%5;
              ans[i]=(rem==0);
        }
   return ans; }
};