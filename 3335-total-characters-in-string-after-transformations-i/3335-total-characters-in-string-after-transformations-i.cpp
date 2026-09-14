class Solution
{
    public:
        int mod = 1e9 + 7;
    int lengthAfterTransformations(string s, int t)
    {
        vector<int> freq(26, 0);
        for (char &x: s)
        {
            freq[x - 'a'] = (freq[x - 'a'] + 1) % mod;
        }

        while (t--)
        {
            vector<int> temp(26, 0);
            for (int i = 0; i < 25; i++)
            {
                temp[(i + 1)] = (freq[i]) % mod;
            }
            temp[1] = (temp[1] + freq[25]) % mod;
            temp[0] = (freq[25])%mod;
            freq = move(temp);
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++)
        {
            cnt = (cnt+freq[i])%mod;
        }
        return cnt;
    }
};