class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();

        int countPositive = n-(upper_bound(begin(nums), end(nums),0)-begin(nums));
        int countNegative = lower_bound(begin(nums), end(nums),0)-begin(nums);

        return max(countPositive, countNegative);
    }
};
