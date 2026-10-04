class Solution {
public:
    int minDays(int n){
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;

        for(int score = 1; score <= n; score++){
            for(int streak = 1; streak * (streak + 1) / 2 <= score; streak++){
                int points = streak * (streak + 1) / 2;
                int days = streak;

                if(score - points > 0){
                    days++;
                }

                dp[score] = min(dp[score], dp[score - points] + days);
            }
        }

        return dp[n];
    }
};