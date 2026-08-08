class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<int> dp(n, 1);

        int ans = 1;

        for (int i = 0; i < n; i++) {

            long long root = sqrt(nums[i]);

            if (root * root != nums[i])
                continue;

            int idx = lower_bound(nums.begin(), nums.begin() + i, (int)root) - nums.begin();

            if (idx < i && nums[idx] == root)
                dp[i] = dp[idx] + 1;

            ans = max(ans, dp[i]);
        }

        return ans >= 2 ? ans : -1;
    }
};