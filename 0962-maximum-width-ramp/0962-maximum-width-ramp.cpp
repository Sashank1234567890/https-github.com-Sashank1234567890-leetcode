class Solution
{
    public:
        int maxWidthRamp(vector<int> &nums)
        {
            int n = nums.size();
            vector<pair<int, int>> v;

            for (int i = 0; i < n; i++)
            {
                v.push_back({ nums[i],i });
            }

            sort(v.begin(), v.end());

            int ans = 0, mx = v[n - 1].second;

            for (int i = n - 2; i >= 0; i--)
            {

                ans = max(ans, mx-v[i].second);
                mx = max(mx, v[i].second);
            }

            return ans;
        }
};