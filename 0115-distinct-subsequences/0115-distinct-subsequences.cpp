class Solution {
public:
    int cnt(string &s, string &t,int i,int j,vector<vector<int>>&dp){
        if(j<0)
        return 1;
        if(i<0)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int ans=0;
        if(s[i]==t[j]){
              ans+=cnt(s,t,i-1,j-1,dp);
        }
        ans+=cnt(s,t,i-1,j,dp);
        return dp[i][j]=ans;
    }
    int numDistinct(string s, string t) {
       int n=s.size();
       int m=t.size();
       vector<vector<int>>dp(n,vector<int>(m,-1));
       return cnt(s,t,n-1,m-1,dp); 
    }
};