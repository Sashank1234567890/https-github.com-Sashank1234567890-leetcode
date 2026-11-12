class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=1;
        int inc=1,dec=1;
        int mx=1;

        while(i<n){
            if(nums[i]>nums[i-1]){
                inc++;
            }else{
                inc=1;
            }

            if(nums[i]<nums[i-1]){
                dec++;
            }else{
                dec=1;
            }

            mx=max({mx,inc,dec});
            i++;
        }

        return mx;
    }
};