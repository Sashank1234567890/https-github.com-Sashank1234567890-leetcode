class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        if(n==2)
        return nums[1]+nums[0];
        ranges::sort(nums);
        int ans=0;

        for(int i=0;i<n;i++)
             ans=max(ans,nums[i]+nums[n-i-1]);

        return ans ;
        
    }
};