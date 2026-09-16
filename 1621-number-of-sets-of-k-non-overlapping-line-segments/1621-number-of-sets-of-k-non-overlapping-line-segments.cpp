class Solution {
public:
    int mod=1e9+7;
    int count(int n,int k,vector<vector<int>>&dp){
        if(k==0)
        return 1;
        if(n<0)
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
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        // dp[0][0]=1;
        // for(int i=1;i<=n-1;i++){
        //     for(int j=1;j<=k;j++){
        //         for(int l=i-1;l>=0;l--){
        //             if(l<j-1){
        //                 break;
        //             }
        //             dp[i][j]=(dp[i][j]+dp[l][j-1])%mod;
        //         }
        //          dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
        //     }
        // }

        return dp[n-1][k]=count(n-1,k,dp);
    }
};