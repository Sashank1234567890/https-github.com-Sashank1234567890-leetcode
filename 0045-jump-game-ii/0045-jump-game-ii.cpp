class Solution
{
    public:
        int jumps(vector<int> &nums, int i, vector<int> &dp)
        {
            int n = nums.size();
            if (i == n-1)
                return 0;
            if(i>=n)
            return 1e5;
            int mn = 1e5;
            if (dp[i] != -1)
                return dp[i];
            for (int j = 1; j <= nums[i]; j++)
            {
                mn = min(mn, 1 + jumps(nums, i + j, dp));
            }
            return dp[i] = mn;
        }
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        if (nums[0] == 0)
            return 0;
        vector<int> dp(n, -1);
        int mn = 2000;
        return jumps(nums,0,dp);
    }
};