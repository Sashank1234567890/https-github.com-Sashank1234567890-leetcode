class Solution
{
public:
    bool wordPattern(string p, string s)
    {
        stringstream ss(s);

        string word;
        int i = 0;
        int n = p.size();

        unordered_map<string, string> mp;

        while (getline(ss, word, ' '))
        {
            if (i == n)
                return false;

            string ch(1, p[i]);

            string wordKey = word + "-W";

            if (mp.contains(wordKey) && mp[wordKey] != ch)
                return false;

            if (mp.contains(ch) && mp[ch] != word)
                return false;

            mp[wordKey] = ch;
            mp[ch] = word;

            i++;
        }

        return i == n;
    }
};