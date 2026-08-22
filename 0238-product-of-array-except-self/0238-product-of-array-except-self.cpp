class Solution
{
    public:
        vector<int> productExceptSelf(vector<int> &nums)
        {
            long long p = 1, q = 1;
            int cnt= 0;
            for (int x: nums)
            {
                if (x == 0)
                {
                    cnt++;
                }
                if (x)
                {
                    q *= x;
                }
                p *= x;
            }
            for (int &x: nums)
            {
                if (x == 0)
                {
                    if (cnt == 1)
                        x = q;
                    else
                    {
                        x = 0;
                    }
                }
                else {
                    x = p / x;
                }

                
            }
            return nums;
        }
};