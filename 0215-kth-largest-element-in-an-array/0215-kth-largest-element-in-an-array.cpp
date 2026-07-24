class Solution
{
    public:

        int partition(vector<int> &nums, int l, int h)
        {

            // int randomIndex = l + rand() % (h - l + 1);
            // swap(nums[l], nums[randomIndex]);

            int pivot = nums[l];
            int i = l + 1;
            int j = h;

            while (i <= j)
            {

                while (i <= h && nums[i] >= pivot)
                    i++;

                while (j >= l + 1 && nums[j] < pivot)
                    j--;

                if (i < j)
                    swap(nums[i], nums[j]);
            }

            swap(nums[l], nums[j]);
            return j;
        }

    int quickSelect(vector<int> &nums, int l, int h, int k)
    {

        if (l == h)
            return nums[l];

        int idx = partition(nums, l, h);

        if (idx == k - 1)
            return nums[idx];

        if (idx > k - 1)
            return quickSelect(nums, l, idx - 1, k);

        return quickSelect(nums, idx + 1, h, k);
    }

    int findKthLargest(vector<int> &nums, int k)
    {

        srand(time(0));

        return quickSelect(nums, 0, nums.size() - 1, k);
    }
};