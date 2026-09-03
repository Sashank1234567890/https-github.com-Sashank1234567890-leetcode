class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        int i=0,j=0;
        while(j<n){
         if(i!=j&&nums[j]==nums[j-1]){
            i=j;
         }
         ans+=j-i+1;
         j++;
        }
    return ans;}
};