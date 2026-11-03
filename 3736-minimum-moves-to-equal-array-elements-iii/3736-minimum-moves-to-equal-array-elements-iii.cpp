class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx=*max_element(begin(nums),end(nums));
        int ans=0;
        for(int i=0;i<nums.size();i++){
             ans+=mx-nums[i];
        }
   return ans; }
};