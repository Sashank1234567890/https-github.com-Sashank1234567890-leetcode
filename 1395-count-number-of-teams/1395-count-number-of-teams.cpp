class Solution {
public:
    int numTeams(vector<int>& rating) {

        int n = rating.size();

        vector<int> inc(n, 0);
        vector<int> dec(n, 0);

        int ans = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < i; j++) {

                if (rating[j] < rating[i]) {
                    inc[i]++;
                    ans += inc[j];
                }

                else if (rating[j] > rating[i]) {
                    dec[i]++;
                    ans += dec[j];
                }
            }
        }

        return ans;
    }
};