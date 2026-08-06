class Solution
{
    public:
        bool check(int x, int t)
        {
            long long prod = 1;
            while (x)
            {
                if ((x % 10) % t == 0 || prod *(x % 10) % t == 0)
                    return 1;
                prod *= (x % 10);
                x /= 10;
            }
            return 0;
        }
    int smallestNumber(int n, int t)
    {
        if (n == 0)
            return 0;
        while (true)
        {
            if (check(n, t))
                return n;
            n++;
        }
        return -1;
    }
};