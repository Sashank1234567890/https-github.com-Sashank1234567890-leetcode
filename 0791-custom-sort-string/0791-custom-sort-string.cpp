class Solution
{
    public:
        string customSortString(string order, string s)
        {

            unordered_map<char, int> mp;

            for (int i = 0; i < order.size(); i++)
                mp[order[i]] = i;

            auto cmp =[& ](char a, char b)
            {

                bool ina = mp.contains(a);
                bool inb = mp.contains(b);

                if (ina && inb)
                    return mp[a] < mp[b];

                if (ina)
                    return true;

                if (inb)
                    return false;

                return false;
            };

            sort(s.begin(), s.end(), cmp);

            return s;
        }
};