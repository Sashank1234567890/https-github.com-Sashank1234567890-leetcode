class Solution {
public:
    int minMoves(vector<int>& nums) {
       
        int mx=INT_MIN;
         int sum=0;
         int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            mx=max(mx,nums[i]);
        }
   return 1LL*n*mx-sum; }
};