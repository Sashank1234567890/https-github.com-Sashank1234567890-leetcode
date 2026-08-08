class Solution {
public:
    long long dividePlayers(vector<int>& skill) {

        vector<int> freq(1001, 0);

        for (int x : skill)
            freq[x]++;

        int idx = 0;

        for (int i = 0; i <= 1000; i++) {
            while (freq[i]--) {
                skill[idx++] = i;
            }
        }

        int n = skill.size();
        int target = skill[0] + skill[n - 1];

        long long ans = 0;

        int i = 0, j = n - 1;

        while (i < j) {

            if (skill[i] + skill[j] != target)
                return -1;

            ans += 1LL * skill[i] * skill[j];

            i++;
            j--;
        }

        return ans;
    }
};