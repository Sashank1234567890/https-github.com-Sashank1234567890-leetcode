class Solution {
public:
    typedef long long ll;

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<ll> pre(n + 1, 0);

        for(int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + stoneValue[i];
        }

        vector<vector<ll>> dp(n, vector<ll>(n, 0));

        for(int len = 2; len <= n; len++) {

            for(int l = 0; l + len - 1 < n; l++) {

                int r = l + len - 1;

                for(int i = l + 1; i <= r; i++) {

                    ll lsum = pre[i] - pre[l];
                    ll rsum = pre[r + 1] - pre[i];

                    if(rsum > lsum) {
                        dp[l][r] = max(dp[l][r],lsum + dp[l][i - 1]);
                    }
                    else if(lsum > rsum) {
                        dp[l][r] = max(dp[l][r],(rsum + dp[i][r]));
                    }
                    else {
                        dp[l][r] = max({dp[l][r],lsum + dp[l][i - 1],rsum + dp[i][r]});
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};