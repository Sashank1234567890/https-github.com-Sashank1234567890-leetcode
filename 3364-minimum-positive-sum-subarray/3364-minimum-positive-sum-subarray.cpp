class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                int len =j-i+1;
                sum+=nums[j];
                if(len<l){
                    continue;
                }
                if(len>r){
                    break;
                }
                if(sum<=0){
                    continue;
                }
                mn=min(mn,sum);

            }
        }
    return mn==INT_MAX?-1:mn;}
};