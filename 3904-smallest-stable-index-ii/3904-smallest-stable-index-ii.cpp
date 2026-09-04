class Solution
{
    public:
        int firstStableIndex(vector<int> &nums, int k)
        {
            int n = nums.size();
            vector<int> sufmin(n);
            sufmin[n - 1] = nums[n - 1];
            for (int i = n - 2; i >= 0; i--)
            {
                sufmin[i] = min(nums[i], sufmin[i + 1]);
            }
            int pre = -1;
            for (int i = 0; i < n; i++)
            {
                pre = max(pre, nums[i]);
                if (pre - sufmin[i] <= k)
                    return i;
            }
            return -1;
        }
};