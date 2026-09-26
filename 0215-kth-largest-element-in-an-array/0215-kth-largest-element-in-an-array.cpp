class Solution
{
public:

    // 3-way partition
    void partition_algo(vector<int>& nums, int L, int R, int P,
                        int& low, int& high)
    {
        int i = L;
        low = L;
        high = R;

        while(i <= high)
        {
            if(nums[i] > P)
            {
                swap(nums[i], nums[low]);
                i++;
                low++;
            }
            else if(nums[i] < P)
            {
                swap(nums[i], nums[high]);
                high--;
            }
            else
            {
                i++;
            }
        }
    }

    // Median of Medians
    int MOM(vector<int>& nums, int L, int R)
    {
        int n = R - L + 1;

        // Base case
        if(n <= 5)
        {
            sort(nums.begin() + L, nums.begin() + R + 1);

            return nums[L + (n - 1) / 2];
        }

        vector<int> medians;

        // Divide into groups of 5
        for(int i = L; i <= R; i += 5)
        {
            int end = min(i + 4, R);

            sort(nums.begin() + i, nums.begin() + end + 1);

            int mid = i + (end - i) / 2;

            medians.push_back(nums[mid]);
        }

        // Median of medians
        return MOM(medians, 0, medians.size() - 1);
    }

    int quickSelect(vector<int>& nums, int L, int R, int k)
    {
        // Base case
        if(L == R)
            return nums[L];

        // Pivot using Median of Medians
        int P = MOM(nums, L, R);

        int low, high;

        // [ > P ][ == P ][ < P ]
        partition_algo(nums, L, R, P, low, high);

        int target = k - 1;

        // k-th largest lies in greater part
        if(target < low)
        {
            return quickSelect(nums, L, low - 1, k);
        }

        // k-th largest is equal to pivot
        else if(target <= high)
        {
            return P;
        }

        // k-th largest lies in smaller part
        else
        {
            return quickSelect(nums, high + 1, R, k);
        }
    }

    int findKthLargest(vector<int>& nums, int k)
    {
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
};