class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        int sz = strs.size();

        vector<pair<int,int>> count(sz);

        for(int i = 0; i < sz; i++) {

            int zero = 0, one = 0;

            for(char ch : strs[i]) {
                if(ch == '0')
                    zero++;
                else
                    one++;
            }

            count[i] = {zero, one};
        }

        vector<vector<vector<int>>> dp(
            m + 1,
            vector<vector<int>>(n + 1,
            vector<int>(sz + 1, 0))
        );

        for(int index = sz - 1; index >= 0; index--) {

            for(int i = 0; i <= m; i++) {

                for(int j = 0; j <= n; j++) {

                    int include = 0;

                    if(count[index].first <= i &&
                       count[index].second <= j) {

                        include = 1 + dp[i - count[index].first]
                                        [j - count[index].second]
                                        [index + 1];
                    }

                    int exclude = dp[i][j][index + 1];

                    dp[i][j][index] = max(include, exclude);
                }
            }
        }

        return dp[m][n][0];
    }
};