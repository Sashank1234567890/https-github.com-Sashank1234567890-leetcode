class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(begin(nums),end(nums),[](int a,int b){ return abs(a)<abs(b);});
        int n =nums.size();
        int k=ceil(n*1.0/2);
        long long ans=0;
        for(int&x:nums){
            cout<<x<<" ";
        }
        for(int j=n-1;j>=0;j--){
            int val=nums[j]*nums[j];
            if(k){
                ans+=val;
                k--;
            }else{
                ans-=val;
            }
        }
        return ans;
    }
};