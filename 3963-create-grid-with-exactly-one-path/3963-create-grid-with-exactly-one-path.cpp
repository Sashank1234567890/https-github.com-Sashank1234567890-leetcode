class Solution {
public:
    // void dfs(vector<string>&grid,int &i,int &j,int& m,int& n){
       
    //          if(i>=m|j>=n)
    //          return ;
    //           grid[i][j]='.';
    //          if(i==m-1&&j==n-1)
    //          return ;
            
              
             
    //          auto isValid=[&](int x,int y){
    //             return !(i>=m||j>=n);
    //          };
    //          if(isValid(i+1,j)){
    //             i++;
               
    //             dfs(grid,i,j,m,n);
    //             return ;
    //          } 
    //          if(isValid(i,j+1)){
    //             j++;
              
    //           dfs(grid,i,j,m,n);
    //             return ;
    //          }
         
    // }
    vector<string> createGrid(int m, int n) {
        vector<string>grid(m,string(n,'#'));
        int i=0,j=0;
        while(i+j<m+n-2){
            grid[i][j]='.';

            if(j+1<n){
                j++;
            }else if(i+1<m){
                i++;
            }
           
        }
        grid[m-1][n-1]='.';
        return grid;
    }
};