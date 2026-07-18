class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int maxVal = *max_element(nums.begin(), nums.end());

        vector<int> freq(maxVal + 1, 0);

        for (int x : nums)
            freq[x]++;

        // cnt[g] = numbers divisible by g
        vector<int> cnt(maxVal + 1, 0);

        for (int g = 1; g <= maxVal; g++) {
            for (int mult = g; mult <= maxVal; mult += g) {
                cnt[g] += freq[mult];
            }
        }

        // exactPairs[g] = pairs having gcd exactly g
        vector<long long> exactPairs(maxVal + 1, 0);

        for (int g = maxVal; g >= 1; g--) {

            long long c = cnt[g];
            exactPairs[g] = c * (c - 1) / 2;

            for (int mult = 2 * g; mult <= maxVal; mult += g) {
                exactPairs[g] -= exactPairs[mult];
            }
        }

        vector<long long> prefix(maxVal + 1, 0);

        for (int g = 1; g <= maxVal; g++) {
            prefix[g] = prefix[g - 1] + exactPairs[g];
        }

        vector<int> ans;

        for (long long q : queries) {

            int g = upper_bound(prefix.begin(), prefix.end(), q) - prefix.begin();

            ans.push_back(g);
        }

        return ans;
    }
};