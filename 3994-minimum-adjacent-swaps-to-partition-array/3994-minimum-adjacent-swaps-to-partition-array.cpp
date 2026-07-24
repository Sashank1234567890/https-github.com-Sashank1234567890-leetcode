class Solution
{
    public:
        int minAdjacentSwaps(vector<int> &nums, int a, int b)
        {

            const int MOD = 1e9 + 7;

            long long ans = 0;
            long long m = 0;	// number of middle elements seen
            long long r = 0;	// number of right elements seen

            for (int x: nums)
            {

                if (x < a)
                {

                   	// All previous M and R form inversions with this L
                    ans += m + r;
                }
                else if (x <= b)
                {

                   	// All previous R form inversions with this M
                    ans += r;
                    m++;
                }
                else
                {

                   	// Right element
                    r++;
                }
            }

            return ans % MOD;
        }
};