class Solution {
public:
    int numTeams(vector<int>& rating) {

        int n = rating.size();

        vector<vector<int>> inc(n, vector<int>(4, 0));
        vector<vector<int>> dec(n, vector<int>(4, 0));

        int ans = 0;

        for (int i = 0; i < n; i++) {

            inc[i][1] = 1;
            dec[i][1] = 1;

            for (int j = 0; j < i; j++) {

                if (rating[j] < rating[i]) {

                    inc[i][2] += inc[j][1];
                    inc[i][3] += inc[j][2];
                }

                else if (rating[j] > rating[i]) {

                    dec[i][2] += dec[j][1];
                    dec[i][3] += dec[j][2];
                }
            }

            ans += inc[i][3];
            ans += dec[i][3];
        }

        return ans;
    }
};