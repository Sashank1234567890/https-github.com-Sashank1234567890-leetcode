class Solution
{
    public:
        int missingMultiple(vector<int> &nums, int k)
        {
            ranges::sort(nums);
            int t=k;
            for (int x: nums)
            {
                if (x > t)
                {
                    return t;
                }
                else if (x == t)
                {
                    t+=k;
                }
            }
            return t;
        }
};