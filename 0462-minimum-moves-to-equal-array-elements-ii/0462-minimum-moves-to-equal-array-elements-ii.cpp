class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        int med=nums[n/2];
        int ans=0;
        for(int &x:nums){
            ans+=abs(x-med);
        }

    return ans;}
};