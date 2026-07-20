class Solution {
public:
    bool isNice(vector<int>& nums, int start, int end) {
        int mask = 0;
        for (int i = start; i <= end; i++) {
            if ((mask & nums[i]) != 0) //dekho and ke liye hume  do palce mai se ek mai zero chahiye to wrost case dek mask mean kisi na kis ke is position pe 1 hai agr ispe zero then it wil be zero for all 
                return false;
            mask |= nums[i];
        }
        return true;
    }

    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isNice(nums, i, j)) {
                    result = max(result, j - i + 1);
                } else {
                    break; 
                }
            }
        }

        return result;
    }
};

