class Solution
{
    public:
        void updateFreq(int operation, int n, vector<int> &freq)
        {
            for (int i = 0; i < 32; i++)
            {
                if (n &(1 << i))
                    freq[i] += operation;
            }
        }

    int getOrSum(vector<int> &freq)
    {
        int num = 0;

        for (int i = 0; i < 32; i++)
        {
            if (freq[i])
                num |= (1 << i);
        }

        return num;
    }

    int minimumDifference(vector<int> &nums, int k)
    {
        int n = nums.size();

        int i = 0;
        int or_sum = 0;
        int min_or_sum = INT_MAX;

        vector<int> freq(32, 0);
        for (int j = 0; j < n; j++)
        {
            updateFreq(1, nums[j], freq);
            or_sum = getOrSum(freq);

            min_or_sum = min(min_or_sum, abs(k - or_sum));

            if (min_or_sum == 0) return 0;	

            while (i < j && or_sum > k)
            {
                updateFreq(-1, nums[i], freq);
                i++;
                or_sum = getOrSum(freq);
                min_or_sum = min(min_or_sum, abs(k - or_sum));
            }
        }

        return min_or_sum;
    }
};