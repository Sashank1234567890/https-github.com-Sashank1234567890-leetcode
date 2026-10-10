class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        map<int, long long, greater<int>> mp;
        int n = nums1.size();
        long long k = 1LL * k1 + k2;

        for (int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - nums2[i]);
            if (diff > 0)
                mp[diff]++;
        }

        while (k > 0 && !mp.empty()) {
            auto it = mp.begin();
            long long x = it->first;
            long long freq = it->second;

            auto nextIt = next(it);

            if (nextIt == mp.end()) {
                long long reduce = min(k, x * freq);
                long long full = reduce / freq;
                long long rem = reduce % freq;

                mp.erase(it);

                if (x - full > 0)
                    mp[x - full] += freq - rem;

                if (rem > 0 && x - full - 1 > 0)
                    mp[x - full - 1] += rem;

                k -= reduce;
                break;
            }

            long long y = nextIt->first;
            long long diff = x - y;
            long long cost = diff * freq;

            if (k >= cost) {
                mp.erase(it);
                mp[y] += freq;
                k -= cost;
            } else {
                long long reduce = k / freq;
                long long rem = k % freq;

                mp.erase(it);

                if (x - reduce > 0)
                    mp[x - reduce] += freq - rem;

                if (rem > 0 && x - reduce - 1 > 0)
                    mp[x - reduce - 1] += rem;

                k = 0;
            }
        }

        long long ans = 0;

        for (auto [diff, freq] : mp)
            ans += 1LL * diff * diff * freq;

        return ans;
    }
};