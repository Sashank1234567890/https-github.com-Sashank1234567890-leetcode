class Solution
{
    public:
        long long gcdSum(vector<int> &nums)
        {
            int n = nums.size();
            int mx=-1;
            for (int i = 0; i < n; i++)
            {   mx=max(mx,nums[i]);
                nums[i] = gcd(mx, nums[i]);
            }
            sort(nums.begin(), nums.end());
            
            long long sum = 0;
            for (int i = 0; i < n / 2; i++)
            {
                sum += gcd(nums[i], nums[n - i - 1]);
            }
            return sum;
        }
};