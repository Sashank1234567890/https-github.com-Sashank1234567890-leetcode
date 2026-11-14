class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int n=nums.size();
        vector<long long> prefix(n+1,0);

        for(int i=0;i<n;i++) {
            prefix[i+1]=prefix[i]+nums[i];
        }

        vector<pair<long long,int>> v;

        for(int i=0;i<=n;i++) {
            v.push_back({prefix[i],i});
        }

        sort(v.begin(),v.end());

        vector<int> suff(n+1,INT_MAX);

        for(int i=n;i>=0;i--) {
            suff[i]=min(suff[i],v[i].second);
            if(i<n) suff[i]=min(suff[i],suff[i+1]);
        }

        int ans=INT_MAX;

        for(int i=0;i<n;i++) {
            long long target=prefix[i]+k;

            int idx=lower_bound(v.begin(),v.end(),make_pair(target,INT_MIN))-v.begin();

            if(idx<=n && suff[idx]>i) {
                ans=min(ans,suff[idx]-i);
            }
        }

        if(ans==INT_MAX) return 0;

        return ans;
    }
};