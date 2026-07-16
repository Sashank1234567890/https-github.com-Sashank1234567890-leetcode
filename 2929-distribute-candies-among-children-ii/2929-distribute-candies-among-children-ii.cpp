class Solution
{
    public:
        long long C2(long long x)
        {
            if (x < 2) return 0;
            return x *(x - 1) / 2;
        }

    long long distributeCandies(int n, int limit)
    {
        long long L = limit + 1;

        return C2(n + 2) -
            3* C2(n - L + 2) +
            3* C2(n - 2 *L + 2) -
            C2(n - 3 *L + 2);
    }
};