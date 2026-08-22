class Solution
{
    public:
        int findMaxLength(vector<int> &nums)
        {
            int pre = 0;
            int n = nums.size();
            for (int i = 0; i < n; i++)
            {
                if (nums[i] == 0)
                {
                    nums[i] = pre - 1;
                    pre = nums[i];
                }
                else
                {
                    nums[i] = pre + 1;
                    pre = nums[i];
                }
            }
            unordered_map<int, int> mp;
            mp[0] = -1;
            int ans = 0;

            for (int i = 0; i < n; i++)
            {
               	// cout<<nums[i];
                if (mp.count(nums[i]))
                {
                    ans = max(ans, i - mp[nums[i]]);
                }
                else
                {
                    mp[nums[i]] = i;
                }
            }
            return ans;
        }
};