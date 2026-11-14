class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        vector<long long> prefix(n+1,0);

        for(int i=0;i<n;i++) {
            prefix[i+1]=prefix[i]+nums[i];
        }

        multiset<long long> st;
        long long ans=LLONG_MAX;

        for(int i=l;i<=n;i++) {
            st.insert(prefix[i-l]);

            if(i-r-1>=0) {
                st.erase(st.find(prefix[i-r-1]));
            }

            auto it=st.lower_bound(prefix[i]);

            if(it!=st.begin()) {
                it--;
                ans=min(ans,prefix[i]-*it);
            }
        }

        if(ans==LLONG_MAX) return -1;

        return ans;
    }
}; 