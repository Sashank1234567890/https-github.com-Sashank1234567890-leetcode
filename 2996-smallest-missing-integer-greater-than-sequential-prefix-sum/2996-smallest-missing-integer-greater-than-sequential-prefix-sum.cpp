class Solution
{
    public:
        int missingInteger(vector<int> &nums)
        {
            int n = nums.size();

            int sum = nums[0];

            for (int i = 1; i < n; i++)
            {
                if (nums[i] == nums[i - 1] + 1)
                {
                    sum += nums[i];
                }
                else
                {
                    break;
                }
            }

            sort(nums.begin(), nums.end());

            int ans = sum;

            while (true)
            {
                auto it = lower_bound(nums.begin(), nums.end(), ans);

                if (it == nums.end() || *it != ans)
                {
                    return ans;
                }

                ans++;
            }
        }
};