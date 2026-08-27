class Solution
{
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        for(int d = -(m - 1); d <= n - 1; d++)
        {
            vector<int> arr;

            int i = max(0, -d);

            while(i < m && i + d < n)
            {
                arr.push_back(grid[i][i + d]);
                i++;
            }

            if(d <= 0)
                sort(arr.begin(), arr.end(), greater<int>());
            else
                sort(arr.begin(), arr.end());

            i = max(0, -d);
            int k = 0;

            while(i < m && i + d < n)
            {
                grid[i][i + d] = arr[k++];
                i++;
            }
        }

        return grid;
    }
};