class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(), res=nums[0], dp[n], dm[n];
        dp[0]=nums[0];
        dm[0]=nums[0];
        for(int i=1; i<n; i++){
            dp[i]=max(nums[i], max(dp[i-1]*nums[i], dm[i-1]*nums[i]));
            dm[i]=min(nums[i], min(dm[i-1]*nums[i], dp[i-1]*nums[i]));
            res=max(res, dp[i]);
            cout<<dp[i]<<" "<<dm[i]<<endl;
        }
        return res;
    }
};