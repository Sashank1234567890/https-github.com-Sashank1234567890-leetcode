class Solution
{
    public:
        vector<vector < int>> groupThePeople(vector<int> &groupSizes)
        {

            unordered_map<int, vector < int>> mp;
            vector<vector < int>> ans;

            for (int i = 0; i < groupSizes.size(); i++)
            {

                int sz = groupSizes[i];

                mp[sz].push_back(i);

                if (mp[sz].size() == sz)
                {
                    ans.push_back(mp[sz]);
                    mp[sz].clear();
                }
            }

            return ans;
        }
};