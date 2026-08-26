class Solution
{
    public:
        string shortestBeautifulSubstring(string s, int k)
        {
            string ans = "";
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
                        // cout<<sidx<<" ";
                    }
                    else if (len == slen)
                    {
                        string s1 = s.substr(sidx, slen);
                        string s2 = s.substr(i, len);
                        if (s2 < s1)
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
                // cout<<sidx<<" ";
            return s.substr(sidx, slen);
        }
};