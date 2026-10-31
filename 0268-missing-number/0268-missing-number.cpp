class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int total=(n*(n+1))/2;
        int sm=0;
        for(int x:nums){
            sm+=x;
        }
        return total-sm;
    }
};