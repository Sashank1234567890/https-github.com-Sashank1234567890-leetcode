class Solution {
public:
    int inc(vector<int>&nums){
         int n=nums.size();
         int i=1;
         int len=1;
         int mx=1;
         while(i<n){
              if(nums[i]>nums[i-1]){
                len++;
                mx=max(len,mx);
              }else{
                len=1;
              }
    
              i++;
         }
         return mx;

    }
        int dec(vector<int>&nums){
         int n=nums.size();
         int i=1;
         int len=1;
         int mx=1;
         while(i<n){
              if(nums[i]<nums[i-1]){
                len++;
              }else{
                len=1;
              }
              mx=max(len,mx);
              i++;
         }
         return mx;

    }
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int inclen=inc(nums);
        int declen=dec(nums);
        return max(inclen,declen);
    }
};