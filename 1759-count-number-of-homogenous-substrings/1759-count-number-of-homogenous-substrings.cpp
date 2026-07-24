class Solution
{
    public:
        int countHomogenous(string s)
        {
            int n = s.length();
            int i = 0;
            int j = 0;
            int ans = 0;
            int MOD=1e9+7;
            while (j < n)
            {
                if (s[j] == s[i])
                {
                    j++;
                }
                else
                {
                    i = j;
                }
                ans = (ans+j - i)%MOD;
            }
            return ans;
        }
};