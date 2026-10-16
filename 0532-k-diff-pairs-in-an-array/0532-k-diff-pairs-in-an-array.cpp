class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;

        unordered_map<int, int> mp;
        int ans = 0;

        for (int x : nums) {
            if (k == 0) {
                if (mp[x] == 1) ans++;
                mp[x]++;
            } else {
                if (mp[x] == 0) {
                    if (mp[x - k] > 0) ans++;
                    if (mp[x + k] > 0) ans++;
                }
                mp[x]++;
            }
        }

        return ans;
    }
};