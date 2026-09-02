class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        ranges::sort(nums);
        bool isEven=1;
        bool isOdd=1;
        for(int &x:nums){
            if(x%2)
            isEven=0;
            else
            isOdd=0;
        }
        if(isEven||isOdd)
        return true;

        return nums[0]%2;
    }
};