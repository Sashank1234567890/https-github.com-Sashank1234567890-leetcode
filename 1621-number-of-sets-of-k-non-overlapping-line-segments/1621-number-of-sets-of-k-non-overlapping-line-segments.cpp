class Solution {
public:
    int mod=1e9+7;
    int count(int n,int k,vector<vector<int>>&dp){
        if(n==0){
            return k==0;
        }
        if(k<0)
        return 0;
        if(dp[n][k]!=-1)
        return dp[n][k];
        int cnt=0;
        for(int i=n-1;i>=0;i--){
            if(i<k-1){
                break;
            }
            cnt=(cnt+count(i,k-1,dp))%mod;
        }
        cnt=(cnt+count(n-1,k,dp))%mod;
        return  dp[n][k]=cnt;
    }
    int numberOfSets(int n, int k) {
        if(k==n-1){
            return 1;
        }
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return count(n-1,k,dp);
    }
};