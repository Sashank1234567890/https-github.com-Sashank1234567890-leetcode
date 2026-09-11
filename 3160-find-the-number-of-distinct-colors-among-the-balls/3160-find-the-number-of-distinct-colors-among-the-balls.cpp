class Solution
{
    public:
        vector<int> queryResults(int limit, vector<vector < int>> &qr)
        {
            unordered_map<int, unordered_set < int>> mp;
            unordered_map<int, int> map;
            vector<int> ans;
            for (auto &q: qr)
            {
                int u = q[0];
                int v = q[1];
                if (map[u])
                {
                    mp[map[u]].erase(u);
                    if (mp[map[u]].size() == 0)
                    {
                        mp.erase(map[u]);
                    }
                }
                mp[v].insert(u);
                map[u] = v;
                ans.push_back(mp.size());
            }
        return ans;}
};