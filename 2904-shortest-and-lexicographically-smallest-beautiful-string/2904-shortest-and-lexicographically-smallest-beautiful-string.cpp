class Solution
{
    public:
        string shortestBeautifulSubstring(string s, int k)
        {
            int sidx = -1;
            int i = 0, j = 0;
            int slen = INT_MAX;
            int cnt = 0;
            int n = s.length();

            while (j < n)
            {
                cnt += (s[j] == '1');

                while (i < j && cnt > k)
                {
                    cnt -= (s[i] == '1');
                    i++;
                }

                while (i <= j && cnt == k)
                {
                    int len = j - i + 1;

                    if (len < slen)
                    {
                        slen = len;
                        sidx = i;
                    }
                    else if (len == slen)
                    {
                        if (s.compare(i, len, s, sidx, slen) < 0)
                        {
                            sidx = i;
                        }
                    }

                    cnt -= (s[i] == '1');
                    i++;
                }

                j++;
            }

            if (slen == INT_MAX)
                return "";

            return s.substr(sidx, slen);
        }
};