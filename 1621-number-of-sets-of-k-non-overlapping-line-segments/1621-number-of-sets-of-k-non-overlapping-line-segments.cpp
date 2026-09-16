class Solution {
public:
    int M = 1e9 + 7;
    int dp[1001][1001];

    int numberOfSets(int n, int K) {

        for (int i = 0; i <= n; i++) {
            dp[0][i] = (i < n) ? 1 : 0;
        }

        for (int k = 1; k <= K; k++) {

            for (int i = n - 1; i >= 0; i--) {
                
                int skip = dp[k][i + 1];

                int take = 0;
                for (int j = i + 1; j < n; j++) {
                    if(n-j<k-1){
                        break;
                    }
                    take = (take + dp[k - 1][j]) % M;
                }

                dp[k][i] = (take + skip) % M;
            }
        }

        return dp[K][0];
    }
};