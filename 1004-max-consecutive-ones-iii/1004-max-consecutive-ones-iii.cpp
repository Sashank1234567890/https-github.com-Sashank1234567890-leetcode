class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int n=nums.size();
        int zero=0;
        int result=0;
        while(j<n){
        zero+=(nums[j]==0);
        while(zero>k){
            zero-=(nums[i]==0);
            i++;
        }
        result=max(result,j-i+1);
        j++;
        }
   return result; }
};