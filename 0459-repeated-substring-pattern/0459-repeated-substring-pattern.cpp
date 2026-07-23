class Solution
{
    public:

        vector<int> buildLPS(string & s)
        {

            int n = s.size();

            vector<int> lps(n, 0);

            int i = 1;
            int len = 0;

            while (i < n)
            {

                if (s[i] == s[len])
                {

                    len++;
                    lps[i] = len;
                    i++;
                }
                else
                {

                    if (len == 0)
                    {
                        lps[i] = 0;
                        i++;
                    }
                    else
                    {
                        len = lps[len - 1];
                    }
                }
            }

            return lps;
        }

    bool repeatedSubstringPattern(string s)
    {

        int n = s.size();

        vector<int> lps = buildLPS(s);

        int len = lps[n - 1];

       	//n-len give th lonegest len repeating

        return (len > 0 && n % (n - len) == 0);
    }
};