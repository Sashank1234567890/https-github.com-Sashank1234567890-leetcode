class Solution
{
public:
    int mod = 1e9 + 7;

    int countNicePairs(vector<int> &nums)
    {
        unordered_map<long long int, int> mp;
        int ans = 0;

        for (int &x : nums)
        {
            string t = to_string(x);
            long long int val = 0;
            int n = t.size();
            long long int pow = 1;

            for (int i = 0; i < n; i++)
            {
                val += (t[n - i - 1] - t[i]) * pow;
                pow *= 10;
            }

            ans = (ans + mp[val]) % mod;
            mp[val]++;
        }

        return ans;
    }
};