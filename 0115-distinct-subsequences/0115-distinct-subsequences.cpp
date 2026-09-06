class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int n = s.size();
        int m = t.size();

        vector<long long> prev(m + 1, 0);
        vector<long long> next(m + 1, 0);

        prev[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            next[0] = 1;

            for (int j = 1; j <= m; j++)
            {
                next[j] = prev[j];

                if (s[i - 1] == t[j - 1])
                {
                    next[j] = min(
                        (long long)INT_MAX,
                        next[j] + prev[j - 1]
                    );
                }
            }

            swap(prev, next);

            fill(next.begin(), next.end(), 0);
        }

        return prev[m];
    }
};