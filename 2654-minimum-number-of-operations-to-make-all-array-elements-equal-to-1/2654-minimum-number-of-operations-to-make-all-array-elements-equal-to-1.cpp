class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        // Count how many 1s are already present
        int ones = 0;

        for (int x : nums) {
            if (x == 1)
                ones++;
        }

        // Each non-1 needs one operation with an existing 1
        if (ones)
            return n - ones;

        // DP state:
        // {g, len} means:
        // g   = GCD of a subarray ending at current index
        // len = minimum length of such a subarray
        vector<pair<int, int>> dp;

        int minLen = INT_MAX;

        for (int x : nums) {
            vector<pair<int, int>> cur;

            // Start a new subarray containing only x
            cur.push_back({x, 1});

            // Extend every previous subarray by x
            for (auto p : dp) {
                int g = gcd(p.first, x);
                int len = p.second + 1;

                // Same GCD state -> keep minimum length
                if (cur.back().first == g)
                    cur.back().second = min(cur.back().second, len);
                else
                    cur.push_back({g, len});
            }

            // Check whether we can make GCD = 1
            for (auto p : cur) {
                if (p.first == 1)
                    minLen = min(minLen, p.second);
            }

            // Move current states to dp for next index
            dp = cur;
        }

        // If no subarray has GCD 1, impossible
        if (minLen == INT_MAX)
            return -1;

        // minLen - 1 operations to create the first 1
        // n - 1 operations to spread that 1 to all elements
        return (minLen - 1) + (n - 1);
    }
};