class Solution {
public:

    int R = 5;

    // 3-way partition
    void partition_algo(vector<int>& nums, int L, int R, int P,
                        int& low, int& high) {

        int i = L;
        low = L;
        high = R;

        while (i <= high) {

            if (nums[i] > P) {
                swap(nums[i], nums[low]);
                i++;
                low++;
            }

            else if (nums[i] < P) {
                swap(nums[i], nums[high]);
                high--;
            }

            else {
                i++;
            }
        }
    }


    // Median of Medians
    int MOM(vector<int>& nums, int L, int R) {

        int n = R - L + 1;

        // If at most 5 elements
        if (n <= 5) {
            sort(nums.begin() + L, nums.begin() + R + 1);

            return nums[L + (n - 1) / 2];
        }

        vector<int> medians;

        // Divide into groups of 5
        for (int i = L; i <= R; i += 5) {

            int end = min(i + 4, R);

            // Sort current group
            sort(nums.begin() + i, nums.begin() + end + 1);

            // Store median
            int mid = i + (end - i) / 2;

            medians.push_back(nums[mid]);
        }

        // Find median of medians
        return MOM(medians, 0, medians.size() - 1);
    }


    int quickSelect(vector<int>& nums, int L, int R, int k) {

        // Choose pivot using Median of Medians
        int P = MOM(nums, L, R);

        int low, high;

        // Partition:
        // [ > P ][ == P ][ < P ]
        partition_algo(nums, L, R, P, low, high);

        // k-1 is required 0-based position
        int target = k - 1;

        // Required element is in greater-than part
        if (target < low) {
            return quickSelect(nums, L, low - 1, k);
        }

        // Required element is equal to pivot
        if (target <= high) {
            return P;
        }

        // Required element is in smaller-than part
        return quickSelect(nums, high + 1, R, k);
    }


    int findKthLargest(vector<int>& nums, int k) {

        return quickSelect(nums, 0, nums.size() - 1, k);
    }
};