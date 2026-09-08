class Solution
{
    public:
        vector<vector < int>> findWinners(vector<vector < int>> &matches)
        {
            map<int, int> mp;
            for (auto &match: matches)
            {
                int w = match[0], l = match[1];
                mp[w];
                mp[l]++;
            }
            vector<vector<int>> ans(2);
            for (auto &[p, val]: mp)
            {
                if (val==0)
                {
                    ans[0].push_back(p);
                }
                else if(val==1)
                {
                    ans[1].push_back(p);
                }
            }
            return ans;
        }
};