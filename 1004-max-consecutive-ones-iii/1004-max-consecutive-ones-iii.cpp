class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int zero =0;
        int i=0,j=0;
        int len=0;
        while(j<n){
              zero+=(nums[j]==0);
             while(i<=j&&zero>k){
                zero-=(nums[i]==0);
                i++;
             }
             len=max(len,j-i+1);
             j++;
        }
        return len;
    }
};