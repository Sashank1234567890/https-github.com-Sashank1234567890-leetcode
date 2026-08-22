class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();

        sort(events.begin(), events.end());

        vector<vector<int>> dp(n+1, vector<int>(3, 0));

        for(int i=n-1;i>=0;i--){
            int l=i+1;
            int r=n-1;
            int next=n;

            while(l<=r){
                int mid=l+(r-l)/2;

                if(events[mid][0]>events[i][1]){
                    next=mid;
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }

            for(int count=1;count>=0;count--){
                int take=events[i][2]+dp[next][count+1];

                int not_take=dp[i+1][count];

                dp[i][count]=max(take,not_take);
            }
        }

        return dp[0][0];
    }
};
