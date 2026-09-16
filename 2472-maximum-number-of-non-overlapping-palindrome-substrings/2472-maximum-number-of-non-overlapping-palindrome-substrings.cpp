class Solution
{
    public:
        bool isPalindrome(const string &s, int i, int j)
        {
            while (i < j)
            {
                if (s[i++] != s[j--]) return false;
            }
            return true;
        }

    int maxPalindromes(string s, int k)
    {
        int n = s.size();
        if (k == 1)
            return n;	

        vector<vector < int>> t(n + 1, vector<int> (n + 1, 0));

        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= i; --j)
            {

                if (isPalindrome(s, i, j))
                {
                    int takeIt = 1 + (j + k <= n ? t[j + 1][j + k] : 0);

                    t[i][j] = max(takeIt,t[i][j]);
                }

                int slideWindow = t[i + 1][j + 1];
                int growWindow = t[i][j + 1];
                t[i][j] = max({ t[i][j],slideWindow,growWindow });}
        }

        return t[0][k - 1];
    }
};