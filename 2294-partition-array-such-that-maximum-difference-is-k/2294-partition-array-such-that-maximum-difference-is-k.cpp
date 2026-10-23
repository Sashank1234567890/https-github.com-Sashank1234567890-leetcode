class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int cnt=1;
        ranges::sort(nums);
        int n=nums.size();
        int x=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]-x>k){
                cnt++;
                x=nums[i];
            }
        }
        return cnt;
    }
};