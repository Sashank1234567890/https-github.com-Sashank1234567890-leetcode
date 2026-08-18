class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            int free=-1;
            for(int j=m-1;j>=0;j--){
                if(grid[i][j]=='.'){
                    if(free==-1)
                      free=j;
                    else 
                    continue;  
                }else if(grid[i][j]=='*'){
                    free=-1;
                }
                else{
                    if(free==-1)
                    continue;
                    grid[i][free]=grid[i][j];
                    grid[i][j]='.';
                    free=free-1;
                }
            }
        }
        vector<vector<char>>mat;
        for(int j=0;j<m;j++){
            vector<char>v;
            for(int i=0;i<n;i++){
                v.push_back(grid[i][j]);
            }
            ranges::reverse(v);
            mat.push_back(v);
        }
    return mat;
    }
};