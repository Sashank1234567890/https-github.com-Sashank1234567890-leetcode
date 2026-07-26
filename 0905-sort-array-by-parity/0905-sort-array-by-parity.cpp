class Solution
{
    public:
        vector<int> sortArrayByParity(vector<int> &nums)
        {
            auto lambda =[& ](int a, int b)
            {
                bool x = (a % 2 == 0);
                bool y = (b % 2 == 0);

                if (x == y)
                    return x < y;

                return x > y;
            };
            ranges::sort(nums, lambda);
            return nums;
        }
};