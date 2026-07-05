class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {

        int m = coins.size();
        int n = coins[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));

        for(int neu = 0; neu <= 2; neu++) {

            if(coins[m-1][n-1] >= 0)
                dp[m-1][n-1][neu] = coins[m-1][n-1];
            else {
                dp[m-1][n-1][neu] = coins[m-1][n-1];

                if(neu > 0)
                    dp[m-1][n-1][neu] = 0;
            }
        }

        for(int i = m-1; i >= 0; i--) {

            for(int j = n-1; j >= 0; j--) {

                if(i == m-1 && j == n-1)
                    continue;

                for(int neu = 0; neu <= 2; neu++) {

                    int ans = INT_MIN;

                    // Don't use neutralizer
                    if(i+1 < m && dp[i+1][j][neu] != INT_MIN)
                        ans = max(ans, coins[i][j] + dp[i+1][j][neu]);

                    if(j+1 < n && dp[i][j+1][neu] != INT_MIN)
                        ans = max(ans, coins[i][j] + dp[i][j+1][neu]);

                    // Use neutralizer
                    if(coins[i][j] < 0 && neu > 0) {

                        if(i+1 < m)
                            ans = max(ans, dp[i+1][j][neu-1]);

                        if(j+1 < n)
                            ans = max(ans, dp[i][j+1][neu-1]);
                    }

                    dp[i][j][neu] = ans;
                }
            }
        }

        return dp[0][0][2];
    }
};