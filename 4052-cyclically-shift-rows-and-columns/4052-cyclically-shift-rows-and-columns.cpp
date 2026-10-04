class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        for(int i=0;i<n;i++){
            int k=rowShift[i]%n;
            vector<int> temp(n);

            for(int j=0;j<n;j++)
                temp[(j-k+n)%n]=grid[i][j];

            grid[i]=temp;
        }

        vector<int> temp(n);

        for(int j=0;j<n;j++){
            int k=colShift[j]%n;

            for(int i=0;i<n;i++)
                temp[(i-k+n)%n]=grid[i][j];

            for(int i=0;i<n;i++)
                grid[i][j]=temp[i];
        }

        return grid;
    }
};