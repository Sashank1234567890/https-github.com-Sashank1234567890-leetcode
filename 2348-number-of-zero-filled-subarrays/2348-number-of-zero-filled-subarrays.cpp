class Solution
{
    public:
        long long zeroFilledSubarray(vector<int> &nums)
        {

            int n = nums.size();
            long long ans = 0;

            int i = 0;

            while (i < n)
            {

                if (nums[i] != 0)
                {
                    i++;
                    continue;
                }

                int j = i;

                while (j < n && nums[j] == 0)
                    j++;

                long long len = j - i;

                ans += len *(len + 1) / 2;

                i = j;
            }

            return ans;
        }
};