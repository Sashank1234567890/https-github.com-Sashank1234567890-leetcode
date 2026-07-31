class Solution
{
    public:
        int minimumPushes(string word)
        {
            vector<int> freq(26, 0);

            for (char c: word)
                freq[c - 'a']++;

            int mx = 0;
            for (int x: freq)
                mx = max(mx, x);

            vector<int> bucket(mx + 1, 0);

            for (int x: freq)
                if (x)
                    bucket[x]++;

            int ans = 0;
            int idx = 0;

            for (int f = mx; f >= 1; f--)
            {
                while (bucket[f]--)
                {
                    ans += f *(idx / 8 + 1);
                    idx++;
                }
            }

            return ans;
        }
};