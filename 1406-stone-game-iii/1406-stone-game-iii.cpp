class Solution
{
    public:
        string stoneGameIII(vector<int> &stoneValue)
        {

            int n = stoneValue.size();

            vector<vector < int>> dp(2, vector<int> (n + 1, 0));

            for (int i = n - 1; i >= 0; i--)
            {

               	// Alice's turn
                dp[1][i] = INT_MIN;
                int stones = 0;

                for (int j = i; j < min(i + 3, n); j++)
                {
                    stones += stoneValue[j];
                    dp[1][i] = max(dp[1][i], stones + dp[0][j + 1]);
                }

               	// Bob's turn
                dp[0][i] = INT_MAX;
                stones = 0;

                for (int j = i; j < min(i + 3, n); j++)
                {
                    stones -= stoneValue[j];
                    dp[0][i] = min(dp[0][i], stones + dp[1][j + 1]);
                }
            }

            int diff = dp[1][0];

            if (diff > 0)
                return "Alice";
            if (diff < 0)
                return "Bob";

            return "Tie";
        }
};