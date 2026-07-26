class Solution
{
    public:
        vector<int> sortArrayByParity(vector<int> &nums)
        {
            auto lambda =[& ](int a, int b)
            {
                return a%2 < b%2;
            };
            ranges::sort(nums, lambda);
            return nums;
        }
};