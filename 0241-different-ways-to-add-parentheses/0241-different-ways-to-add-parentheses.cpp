class Solution {
public:

    vector<vector<vector<int>>> dp;
    string s;

    vector<int> solve(int i, int j) {

     
        if (!dp[i][j].empty()) {
            return dp[i][j];
        }

        vector<int> result;

        for (int k = i; k <= j; k++) {

            if (s[k] == '+' || s[k] == '-' || s[k] == '*') {

                vector<int> left = solve(i, k - 1);
                vector<int> right = solve(k + 1, j);

                for (int x : left) {
                    for (int y : right) {

                        if (s[k] == '+')
                            result.push_back(x + y);

                        else if (s[k] == '-')
                            result.push_back(x - y);

                        else
                            result.push_back(x * y);
                    }
                }
            }
        }

      
        if (result.empty()) {
            result.push_back(stoi(s.substr(i, j - i + 1)));
        }

        return dp[i][j] = result;
    }

    vector<int> diffWaysToCompute(string expression) {

        s = expression;

        int n = s.length();

        dp.resize(n, vector<vector<int>>(n));

        return solve(0, n - 1);
    }
};