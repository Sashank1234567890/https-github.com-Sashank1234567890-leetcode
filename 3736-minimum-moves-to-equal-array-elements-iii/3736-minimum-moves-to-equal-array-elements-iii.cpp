class Solution {
public:
    int minMoves(vector<int>& nums) {
       
        int mx=nums[0];
         int ans=0;
        for(int i=1;i<nums.size();i++){
             if(nums[i]>mx){
                int diff=nums[i]-mx;
                mx=nums[i];
                ans+=i*diff;
             }else{
                ans+=mx-nums[i];
             }
        }
   return ans; }
};