class Solution
{
    public:
        int waysToSplitArray(vector<int> &nums)
        {
            long long int ts = 0;
            for (int x: nums)
            {
                ts += x;
            }
            long long int pre = 0, cnt = 0;
            for (int i = 0; i < nums.size() - 1; i++)
            {
                pre += nums[i];
                if (pre >= ts - pre)
                {
                    cnt++;
                }
            }
            return cnt;
        }
};