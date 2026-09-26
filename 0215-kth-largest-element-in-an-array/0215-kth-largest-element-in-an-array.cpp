class Solution
{
public:

    pair<int, int> partition_algo(vector<int> &arr, int L, int R)
    {
        int p = arr[R];

        int l = L, m = L, h = R;

        while(m <= h)
        {
            if(arr[m] > p)
            {
                swap(arr[l], arr[m]);
                l++;
                m++;
            }
            else if(arr[m] < p)
            {
                swap(arr[m], arr[h]);
                h--;
            }
            else
            {
                m++;
            }
        }

        return {l, h};
    }

    int quickSelect(vector<int> &nums, int L, int R, int k)
    {
        if(L >= R)
            return nums[L];

        auto [lt, gt] = partition_algo(nums, L, R);

        int leftSize = lt - L;
        int equalSize = gt - lt + 1;

        if(k <= leftSize)
        {
            return quickSelect(nums, L, lt - 1, k);
        }
        else if(k <= leftSize + equalSize)
        {
            return nums[lt];
        }
        else
        {
            return quickSelect(nums, gt + 1, R,k - leftSize - equalSize);
        }
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
};