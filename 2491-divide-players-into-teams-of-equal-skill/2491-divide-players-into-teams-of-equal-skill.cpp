class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();

        vector<int> freq(1001, 0);

        int sum = 0;
        for (int x : skill) {
            sum += x;
            freq[x]++;
        }

        int teams = n / 2;

        if (sum % teams != 0)
            return -1;

        int target = sum / teams;

        long long ans = 0;

        for (int x : skill) {

            if (freq[x] == 0)
                continue;

            freq[x]--;

            int y = target - x;

            if (y < 0 || y > 1000 || freq[y] == 0)
                return -1;

            freq[y]--;

            ans += 1LL * x * y;
        }

        return ans;
    }
};