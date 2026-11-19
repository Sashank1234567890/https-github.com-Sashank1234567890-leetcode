class Solution {
public:
    int minimizeSum(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      int n=nums.size();
      vector<int>copy=nums;
      copy[0]=copy[n/2];
      copy[n-1]=copy[n/2];
      return min({ranges::max(nums)-nums[2],nums[n-3]-ranges::min(nums),ranges:: max(copy)-ranges:: min(copy)});
    }
};