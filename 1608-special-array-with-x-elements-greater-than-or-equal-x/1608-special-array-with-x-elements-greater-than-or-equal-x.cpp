class Solution {
public:

    int specialArray(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        
        int l = 0, r = n;
        while(l <= r) {
            int mid_x = l + (r-l)/2;

            int i = lower_bound(begin(nums), end(nums), mid_x) - begin(nums);

            if(n-i == mid_x) {
                return mid_x;
            } else if(n-i > mid_x) {
                l = mid_x+1;
            } else {
                r = mid_x-1;
            }
        }

        return -1;
    }
};
