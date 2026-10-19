class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        ranges::sort(nums);
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target)
            ans.push_back(i);
            else if(nums[i]>target)
            break;
        }
        return ans;
    }
};