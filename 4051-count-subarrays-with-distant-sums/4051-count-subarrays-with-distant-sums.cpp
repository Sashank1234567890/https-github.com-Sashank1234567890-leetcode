class Solution {
public:
    vector<int> seg;
    int m;

    void update(int node,int l,int r,int pos){
        if(l==r){
            seg[node]++;
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid)
            update(2*node,l,mid,pos);
        else
            update(2*node+1,mid+1,r,pos);
        seg[node]=seg[2*node]+seg[2*node+1];
    }

    int query(int node,int l,int r,int ql,int qr){
        if(ql>r||qr<l)
            return 0;
        if(ql<=l&&r<=qr)
            return seg[node];
        int mid=(l+r)/2;
        return query(2*node,l,mid,ql,qr)+query(2*node+1,mid+1,r,ql,qr);
    }

    long long distantSubarrays(vector<int>& nums,int goal,int k){
        int n=nums.size();

        if(k==0)
            return 1LL*n*(n+1)/2;

        vector<long long> pre(n+1,0);

        for(int i=0;i<n;i++)
            pre[i+1]=pre[i]+nums[i];

        vector<long long> v=pre;
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());

        m=v.size();
        seg.assign(4*m,0);

        long long ans=0;

        for(int j=0;j<=n;j++){
            long long lowNeed=pre[j]-(1LL*goal-k);
            long long highNeed=pre[j]-(1LL*goal+k);

            int lowPos=lower_bound(v.begin(),v.end(),lowNeed)-v.begin();

            if(lowPos<m)
                ans+=query(1,0,m-1,lowPos,m-1);

            int highPos=upper_bound(v.begin(),v.end(),highNeed)-v.begin()-1;

            if(highPos>=0)
                ans+=query(1,0,m-1,0,highPos);

            int pos=lower_bound(v.begin(),v.end(),pre[j])-v.begin();
            update(1,0,m-1,pos);
        }

        return ans;
    }
};