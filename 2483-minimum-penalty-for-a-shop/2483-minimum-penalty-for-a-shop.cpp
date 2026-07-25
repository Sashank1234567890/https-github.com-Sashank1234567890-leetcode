class Solution {
public:
    int bestClosingTime(string customers) {

        int n = customers.size();

        vector<int> prefixN(n + 1, 0);
        vector<int> prefixY(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefixN[i + 1] = prefixN[i];
            prefixY[i + 1] = prefixY[i];

            if (customers[i] == 'N')
                prefixN[i + 1]++;
            else
                prefixY[i + 1]++;
        }

        int ans = 0;
        int mn = INT_MAX;

        for (int j = 0; j <= n; j++) {

            int penalty = prefixN[j] + (prefixY[n] - prefixY[j]);

            if (penalty < mn) {
                mn = penalty;
                ans = j;
            }
        }

        return ans;
    }
};