class Solution {
public:
    bool canSortArray(vector<int>& nums) {

        int n = nums.size();

        vector<int> bits(n);

        for (int i = 0; i < n; i++)
            bits[i] = __builtin_popcount(nums[i]);

        for (int i = 0; i < n - 1; i++) {

            bool ok = false;

            for (int j = 0; j < n - i - 1; j++) {

                if (nums[j] > nums[j + 1]) {

                    if (bits[j] != bits[j + 1])
                        return false;

                    swap(nums[j], nums[j + 1]);
                    swap(bits[j], bits[j + 1]);

                    ok = true;
                }
            }

            if (!ok)
                break;
        }

        return true;
    }
};