class Solution
{
    public:
        long long countBadPairs(vector<int> &nums)
        {
            unordered_map<int, int> mp;
            int n = nums.size();
            for (int i = 0; i < n; i++)
            {
                mp[nums[i] - i]++;
            }
            long long ans = 0;
            for (auto &[diff, x]: mp)
            {
                ans = ans + (n - x) *x;
                n -= x;
            }
            return ans;
        }
};