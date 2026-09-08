class Solution
{
    public:
        bool uniqueOccurrences(vector<int> &arr)
        {
            unordered_map<int, int> mp;
            for (int &x: arr)
            {
                mp[x]++;
            }
            unordered_set<int> st;
            for (auto &[x, val]: mp)
            {
                if (st.contains(val))
                    return 0;
                st.insert(val);
            }
            return true;
        }
};