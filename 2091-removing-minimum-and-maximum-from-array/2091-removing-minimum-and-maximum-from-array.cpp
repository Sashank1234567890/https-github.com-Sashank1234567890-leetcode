class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n<=0)
        return n;
        int mnidx=-1;
        int mxidx=-1;
        int mn=INT_MAX,mx=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]>mx){
                mx=nums[i];
                mxidx=i;
            }
            if(nums[i]<mn){
                mn=nums[i];
                mnidx=i;
            }
        }
    return min({mnidx+1+n-mxidx,mxidx+1+n-mnidx,n-min(mxidx,mnidx),max(mnidx,mxidx)+1});
    }
};