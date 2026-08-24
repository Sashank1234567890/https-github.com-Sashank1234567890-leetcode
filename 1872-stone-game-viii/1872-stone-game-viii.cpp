class Solution {
public:
    int n;
    vector<int> pre;
    vector<int> dp;
    // dp[i] = maximum score difference (current player − other player) that can be obtained when the game starts from prefix index i.

    int game(int i) {

        if(i == n - 1)
            return pre[i];

        if(dp[i] != INT_MIN)
            return dp[i];

        int score = game(i + 1);

        return dp[i] = max(score, pre[i] - score);
    }

    int stoneGameVIII(vector<int>& stones) {
 
        n = stones.size();

        pre.resize(n);

        pre[0] = stones[0];

        for(int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + stones[i];
        }

        dp.assign(n, INT_MIN);

        return game(1);
    }
};