class Solution
{
    public:
        int maxProduct(int n)
        {
            int mx = -1;
            int smx = -1;
            while (n)
            {
                int ld = n % 10;
                n /= 10;
                if (mx == -1)
                {
                    mx = ld;
                }
                else if (ld > mx)
                {
                    smx = mx;
                    mx = ld;
                }
                else if (ld > smx)
                {
                    smx = ld;
                }
            }
            return mx * smx;
        }
};