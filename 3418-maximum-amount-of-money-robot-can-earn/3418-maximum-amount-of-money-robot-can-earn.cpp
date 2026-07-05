class Solution {
public:
    int m, n;
    int t[501][501][3];

    int solve(vector<vector<int>>& coins, int i, int j, int neu) {

        if(i >= m || j >= n)
            return INT_MIN;

        if(i == m-1 && j == n-1) {
            if(coins[i][j] >= 0)
                return coins[i][j];

            if(neu > 0)
                return 0;

            return coins[i][j];
        }

        if(t[i][j][neu] != INT_MIN)
            return t[i][j][neu];

        int ans = INT_MIN;

        // Don't use neutralizer
        int down = solve(coins, i+1, j, neu);
        int right = solve(coins, i, j+1, neu);

        if(down != INT_MIN)
            ans = max(ans, coins[i][j] + down);

        if(right != INT_MIN)
            ans = max(ans, coins[i][j] + right);

        // Use neutralizer
        if(coins[i][j] < 0 && neu > 0) {

            down = solve(coins, i+1, j, neu-1);
            right = solve(coins, i, j+1, neu-1);

            ans = max(ans, down);
            ans = max(ans, right);
        }

        return t[i][j][neu] = ans;
    }

    int maximumAmount(vector<vector<int>>& coins) {

        m = coins.size();
        n = coins[0].size();

        for(int i = 0; i < 501; i++)
            for(int j = 0; j < 501; j++)
                for(int k = 0; k < 3; k++)
                    t[i][j][k] = INT_MIN;

        return solve(coins, 0, 0, 2);
    }
};