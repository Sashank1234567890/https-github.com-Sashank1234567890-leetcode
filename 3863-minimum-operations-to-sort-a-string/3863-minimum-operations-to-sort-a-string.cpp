class Solution
{
    public:
        int minOperations(string s)
        {
            string t = "";
            vector<int> freq(26, 0);
            int mnidx = -1, mxidx = -1;
            for (char &x: s)
            {
                int idx = x - 'a';
                freq[idx]++;
            }
            vector<int> copy = freq;
            for (int i = 0; i < 26; i++)
            {
                while (copy[i] > 0)
                {
                    t.push_back('a' + i);
                    copy[i]--;
                }
            }

            cout << t;
            if (t == s)
                return 0;

            for (int i = 0; i < 26; i++)
            {
                if (!freq[i])
                    continue;
                if (mnidx == -1)
                    mnidx = i;
                mxidx = i;
            }
            if (mnidx == mxidx)
                return 0;
            if (mnidx == s[0] - 'a' && mxidx == s.back() - 'a')
            {
                return 1;
            }
            if (mnidx == s[0] - 'a' || mxidx == s.back() - 'a')
                return 1;
            if (s.size() == 2)
                return -1;
            if (mnidx == s.back() - 'a' && mxidx == s[0] - 'a')
            {
                if (freq[mnidx] > 1 || freq[mxidx] > 1)
                {
                    return 2;
                }
                else
                    return 3;
            }

            return 2;
        }
};