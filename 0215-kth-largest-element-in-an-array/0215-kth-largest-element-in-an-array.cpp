class Solution
{
    public:

        int partition_algo(vector<int> &nums, int L, int R)
        {

            int P = nums[L];
            int i = L + 1;
            int j = R;

            while (i <= j)
            {

                if (nums[i] < P && nums[j] > P)
                {
                    swap(nums[i], nums[j]);
                    i++;
                    j--;
                }

                if (nums[i] >= P)
                    i++;

                if (nums[j] <= P)
                    j--;
            }

            swap(nums[L], nums[j]);
            return j;
        }

    int quickSelect(vector<int> &nums, int L, int R, int k)
    {

        int pivot_idx = partition_algo(nums, L, R);

        if (pivot_idx == k - 1)
            return nums[pivot_idx];

        if (pivot_idx > k - 1)
            return quickSelect(nums, L, pivot_idx - 1, k);

        return quickSelect(nums, pivot_idx + 1, R, k);
    }

    int findKthLargest(vector<int> &nums, int k)
    {

        return quickSelect(nums, 0, nums.size() - 1, k);
    }
};