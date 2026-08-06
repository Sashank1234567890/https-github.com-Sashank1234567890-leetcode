class Solution
{
    public:
        bool check(int x, int t)
        {
            int prod = 1 % t;

            while (x)
            {
                prod = (prod *(x % 10)) % t;

                if (prod == 0)
                    return true;

                x /= 10;
            }

            return false;
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