class Solution {
public:
    typedef long long ll;
    ll M=1e9+7;

    pair<ll,ll> countSum(vector<int>& nums,int n,ll x) {

        vector<ll> pre(n+1,0), pp(n+2,0);

        for(int i=0;i<n;i++)
            pre[i+1]=pre[i]+nums[i];

        for(int i=0;i<=n;i++)
            pp[i+1]=pp[i]+pre[i];

        ll cnt=0,sum=0;
        int l=0;

        for(int r=0;r<n;r++) {

            while(pre[r+1]-pre[l]>x)
                l++;

            ll len=r-l+1;

            cnt+=len;

            sum+=len*pre[r+1]-(pp[r+1]-pp[l]);
        }

        return {cnt,sum};
    }

    ll kthSum(vector<int>& nums,int n,ll k) {

        if(k==0)
            return 0;

        ll lo=1,hi=0;

        for(int x:nums)
            hi+=x;

        while(lo<hi) {

            ll mid=(lo+hi)/2;

            auto [cnt,sum]=countSum(nums,n,mid);

            if(cnt>=k)
                hi=mid;
            else
                lo=mid+1;
        }

        auto [cnt,sum]=countSum(nums,n,lo);

        return sum-(cnt-k)*lo;
    }

    int rangeSum(vector<int>& nums,int n,int left,int right) {

        ll r=kthSum(nums,n,right);
        ll l=kthSum(nums,n,left-1);

        return (r-l)%M;
    }
};