class Solution
{
public:

    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans;

        for (int i = 0; i + k <= m; i++)
        {
            vector<int> row;

            for (int j = 0; j + k <= n; j++)
            {
                vector<int> v;

                for (int p = i; p < i + k; p++)
                {
                    for (int q = j; q < j + k; q++)
                    {
                        v.push_back(grid[p][q]);
                    }
                }

                sort(v.begin(), v.end());

                int mn = INT_MAX;

                for (int x = 1; x < v.size(); x++)
                {
                    if (v[x] != v[x - 1])
                    {
                        mn = min(mn, v[x] - v[x - 1]);
                    }
                }

                if (mn == INT_MAX)
                    mn = 0;

                row.push_back(mn);
            }

            ans.push_back(row);
        }

        return ans;
    }
};