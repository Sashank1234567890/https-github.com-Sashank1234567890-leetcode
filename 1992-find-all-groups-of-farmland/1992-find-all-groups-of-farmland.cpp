class Solution {
public:
     void dfs(vector<vector<int>>& grid,int i,int j,int &x,int &y){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0||j<0||j>=m||i>=n||grid[i][j]==0)
        return ;
        x=max(x,i);
        y=max(y,j);
        grid[i][j]=0;
        dfs(grid,i-1,j,x,y);
        dfs(grid,i,j-1,x,y);
        dfs(grid,i+1,j,x,y);
        dfs(grid,i,j+1,x,y);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& grid) {
         int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int x=i,y=j;
                    dfs(grid,i,j,x,y);
                    ans.push_back({i,j,x,y});
                }

            }
        }
    return ans;}
};