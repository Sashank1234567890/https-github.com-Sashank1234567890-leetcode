class Solution
{
    public:
        int mod = 1e9 + 7;

    int dp[205][205][205];

    int cnt(int i, vector<int> &nums, int gcd1, int gcd2)
    {

        if (i == nums.size())
        {
            if (gcd1 == 0 || gcd2 == 0)
                return 0;

            return gcd1 == gcd2;
        }

        if (dp[i][gcd1][gcd2] != -1)
            return dp[i][gcd1][gcd2];

        long long ans = 0;

       	// take in first
        ans = (ans + cnt(i + 1, nums, gcd(gcd1, nums[i]), gcd2)) % mod;

       	// take in second
        ans = (ans + cnt(i + 1, nums, gcd1, gcd(gcd2, nums[i]))) % mod;

       	// don't take
        ans = (ans + cnt(i + 1, nums, gcd1, gcd2)) % mod;

        return dp[i][gcd1][gcd2] = ans;
    }

    int subsequencePairCount(vector<int> &nums)
    {

        memset(dp, -1, sizeof(dp));

        return cnt(0, nums, 0, 0);
    }
};