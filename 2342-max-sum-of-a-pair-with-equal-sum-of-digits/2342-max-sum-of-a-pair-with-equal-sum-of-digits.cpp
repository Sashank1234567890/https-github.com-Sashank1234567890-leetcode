class Solution
{
    public:
        int dsum(int n)
        {
            int sum = 0;
            while (n)
            {
                sum += n % 10;
                n /= 10;
            }
            return sum;
        }
    int maximumSum(vector<int> &nums)
    {
        unordered_map<int, vector < int>> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int sum = dsum(nums[i]);
            if (!mp.contains(sum))
                mp[sum] = { INT_MIN,
                    INT_MIN
                };
            if (mp[sum][1] < nums[i])
            {
                mp[sum][0] = mp[sum][1];
                mp[sum][1] = nums[i];
            }
            else if (nums[i] > mp[sum][0])
            {
                mp[sum][0] = nums[i];
            }
        }
        int ans = -1;
        for (auto[x, v]: mp)
        {
            ans = max(ans, v[0] + v[1]);
        }
        return ans;
    }
};