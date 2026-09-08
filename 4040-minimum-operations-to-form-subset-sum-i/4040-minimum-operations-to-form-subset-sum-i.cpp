class Solution {
public:
    int minOperations(vector<int>& nums, int sum)
    {
        int n = nums.size();
        const int INF = 1e9;

        vector<vector<int>> dp(
            n + 1,
            vector<int>(sum + 1, INF)
        );

        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int s = 1; s <= sum; s++)
            {
                int skip = dp[i + 1][s];

                int takeMultiply = INF;

                int val = nums[i];
                int cost = 0;

                while (val <= s)
                {
                    if (dp[i + 1][s - val] != INF)
                    {
                        takeMultiply = min(
                            takeMultiply,
                            cost + dp[i + 1][s - val]
                        );
                    }

                    if (val > s / 2)
                        break;

                    val *= 2;
                    cost++;
                }

                int takeDivide = INF;

                val = nums[i];
                cost = 0;

                while (val > 0)
                {
                    if (val <= s &&
                        dp[i + 1][s - val] != INF)
                    {
                        takeDivide = min(
                            takeDivide,
                            cost + dp[i + 1][s - val]
                        );
                    }

                    val /= 2;
                    cost++;
                }

                dp[i][s] = min({
                    skip,
                    takeMultiply,
                    takeDivide
                });
            }
        }

        return dp[0][sum] == INF ? -1 : dp[0][sum];
    }
};