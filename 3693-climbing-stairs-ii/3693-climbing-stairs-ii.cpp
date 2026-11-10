class Solution {
public:
    int climbStairs(int n, vector<int>& cost) {
        vector<vector<int>>dp(n+1,vector<int>(4,1e5+1));
        dp[0][0]=dp[0][1]=dp[0][2]=dp[0][3]=0;
        for(int i=1;i<=n;i++){
            for(int j=max(i-3,0);j<i;j++){
                dp[i][i-j]=min({dp[j][1],dp[j][2],dp[j][3]})+cost[i-1]+(i-j)*(i-j);
            }
        }
        // for(auto &v:dp){
        //     for(int &x:v){
        //         cout<<x<<" ";
        //     }
        //     cout<<endl;
        // }
    return min({dp[n][3],dp[n][1],dp[n][2]});}
};