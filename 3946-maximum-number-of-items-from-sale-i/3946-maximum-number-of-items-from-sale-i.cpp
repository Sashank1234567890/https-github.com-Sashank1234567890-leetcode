class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int bud) {
        int n=items.size();
        vector<int> div(1501);
        int mn=INT_MAX;

        for(int i=0;i<n;i++){
            int fac=items[i][0];
            mn=min(mn,items[i][1]);

            for(int j=1;j<=1500;j++){
                if(fac%j==0){
                    div[j]++;
                }
            }
        }

        sort(begin(items),end(items),[&](auto a,auto b){
            return a[1]<b[1];
        });

        vector<int> dp(bud+1,-1);
        dp[0]=0;

        for(int i=0;i<n;i++){
            int cnt=div[items[i][0]];
            int cost=items[i][1];

            for(int j=bud;j>=cost;j--){
                if(dp[j-cost]!=-1){
                    dp[j]=max(dp[j],dp[j-cost]+cnt);
                }
            }
        }

        int ans=0;

        for(int i=0;i<=bud;i++){
            if(dp[i]!=-1){
                ans=max(ans,dp[i]+(bud-i)/mn);
            }
        }

        return ans;
    }
};