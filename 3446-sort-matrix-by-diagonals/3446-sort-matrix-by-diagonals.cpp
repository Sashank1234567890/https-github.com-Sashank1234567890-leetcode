class Solution
{
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                mp[j - i].push_back(grid[i][j]);
            }
        }

        for(auto &x : mp)
        {
            if(x.first <= 0)
                sort(x.second.begin(), x.second.end(), greater<int>());
            else
                sort(x.second.begin(), x.second.end());
        }

        for(int d = -(m - 1); d <= n - 1; d++)
        {
            int k = 0;

            for(int i = 0; i < m; i++)
            {
                int j = i + d;

                if(j >= 0 && j < n)
                    grid[i][j] = mp[d][k++];
            }
        }

        return grid;
    }
};