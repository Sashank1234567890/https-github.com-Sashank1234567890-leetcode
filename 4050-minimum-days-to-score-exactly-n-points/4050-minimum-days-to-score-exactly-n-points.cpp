class Solution {
public:
    vector<int> dp;

    int score(int n){
        if(n == 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int ans = 1e9;
        for(int streak = 1; streak * (streak + 1) / 2 <= n; streak++){
            int points = streak * (streak + 1) / 2;
            int next = score(n - points);
            if(next != 1e9){
                int days = streak;
                if(n - points > 0){
                    days++;
                }
                ans = min(ans, next + days);
            }
        }
        return dp[n] = ans;
    }

    int minDays(int n){
        dp.assign(n + 1, -1);
        return score(n);
    }
};