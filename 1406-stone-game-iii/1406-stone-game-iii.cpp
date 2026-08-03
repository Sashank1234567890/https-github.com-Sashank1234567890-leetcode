class Solution
{
    public:
        string stoneGameIII(vector<int> &stoneValue)
        {

            int n = stoneValue.size();

            vector<vector < int>> dp(2, vector<int> (4, 0));

            for (int i = n - 1; i >= 0; i--)
            {

               	// Alice
                dp[1][i % 4] = INT_MIN;
                int stones = 0;

                for (int j = i; j < min(i + 3, n); j++)
                {
                    stones += stoneValue[j];
                    dp[1][i % 4] = max(dp[1][i % 4],
                        stones + dp[0][(j + 1) % 4]);
                }

               	// Bob
                dp[0][i % 4] = INT_MAX;
                stones = 0;

                for (int j = i; j < min(i + 3, n); j++)
                {
                    stones -= stoneValue[j];
                    dp[0][i % 4] = min(dp[0][i % 4],
                        stones + dp[1][(j + 1) % 4]);
                }
            }

            int diff = dp[1][0];

            if (diff > 0) return "Alice";
            if (diff < 0) return "Bob";
            return "Tie";
        }
};