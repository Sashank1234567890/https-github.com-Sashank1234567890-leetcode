class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        int ans = INT_MAX;

        for (int r = 0; r < n; r++) {
            int cost = r;

            for (int i = 0; i < n / 2; i++) {
                char a = s[(i + r) % n];
                char b = s[(n - 1 - i + r) % n];

                int diff = abs(a - b);

                cost += min(diff, 26 - diff);
            }

            ans = min(ans, cost);
        }

        return ans;
    }
};