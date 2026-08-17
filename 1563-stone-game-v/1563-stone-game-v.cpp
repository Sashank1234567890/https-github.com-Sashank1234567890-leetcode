class Solution {
public:
    typedef long long ll;

    vector<ll> pre;
    vector<vector<int>> dp;

    int solve(vector<int>& stoneValue, int l, int r) {
        if(l == r)
            return 0;

        if(dp[l][r] != -1)
            return dp[l][r];

        ll ans = 0;

        for(int i = l + 1; i <= r; i++) {
            ll lsum = pre[i] - pre[l];
            ll rsum = pre[r + 1] - pre[i];

            if(rsum > lsum) {
                ans = max(ans,lsum + solve(stoneValue, l, i - 1));
            }
            else if(lsum > rsum) {
                ans = max(ans,rsum + solve(stoneValue, i, r));
            }
            else {
                ans = max({ans,lsum + solve(stoneValue, l, i - 1),rsum + solve(stoneValue, i, r)});
            }
        }

        return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        pre.assign(n + 1, 0);

        for(int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + stoneValue[i];

        dp.assign(n, vector<int>(n, -1));

        return solve(stoneValue, 0, n - 1);
    }
};