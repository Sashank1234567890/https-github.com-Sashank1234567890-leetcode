class Solution {
public:
    typedef long long ll;

    ll maxSumTrionic(vector<int> &nums) {

        int n = nums.size();

        vector<vector<ll>> dp(n + 1, vector<ll>(4, LLONG_MIN / 2));

        dp[n][3] = 0;

        for (int i = n - 1; i >= 0; i--) {

            for (int trend = 3; trend >= 0; trend--) {

                ll take = LLONG_MIN / 2;
                ll skip = LLONG_MIN / 2;

                if (trend == 0)
                    skip = dp[i + 1][0];

                if (trend == 3)
                    take = nums[i];

                if (i + 1 < n) {

                    int curr = nums[i];
                    int next = nums[i + 1];

                    if (trend == 0 && next > curr) {

                        take = max(take, 1LL * curr + dp[i + 1][1]);

                    }
                    else if (trend == 1) {

                        if (next > curr)
                            take = max(take, 1LL * curr + dp[i + 1][1]);

                        else if (next < curr)
                            take = max(take, 1LL * curr + dp[i + 1][2]);

                    }
                    else if (trend == 2) {

                        if (next < curr)
                            take = max(take, 1LL * curr + dp[i + 1][2]);

                        else if (next > curr)
                            take = max(take, 1LL * curr + dp[i + 1][3]);

                    }
                    else if (trend == 3 && next > curr) {

                        take = max(take, 1LL * curr + dp[i + 1][3]);

                    }
                }

                dp[i][trend] = max(take, skip);
            }
        }

        return dp[0][0];
    }
};