class Solution
{
    public:
        const int MOD = 1e9 + 7;

    long long merge(vector<int> &arr, int l, int mid, int r)
    {

        vector<int> temp;
        int i = l;
        int j = mid + 1;
        long long inv = 0;

        while (i <= mid && j <= r)
        {

            if (arr[i] <= arr[j])
            {
                temp.push_back(arr[i++]);
            }
            else
            {
                inv += (mid - i + 1);
                temp.push_back(arr[j++]);
            }
        }

        while (i <= mid)
            temp.push_back(arr[i++]);

        while (j <= r)
            temp.push_back(arr[j++]);

        for (int k = l; k <= r; k++)
            arr[k] = temp[k - l];

        return inv;
    }

    long long mergeSort(vector<int> &arr, int l, int r)
    {

        if (l >= r)
            return 0;

        int mid = (l + r) / 2;

        long long inv = 0;

        inv += mergeSort(arr, l, mid);
        inv += mergeSort(arr, mid + 1, r);
        inv += merge(arr, l, mid, r);

        return inv;
    }

    int minAdjacentSwaps(vector<int> &nums, int a, int b)
    {

        int n = nums.size();

        vector<int> zeroPos, onePos;

       	// Store original positions of each group
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < a)
                zeroPos.push_back(i);
            else if (nums[i] <= b)
                onePos.push_back(i);
        }

        vector<int> perm(n);

        int p0 = 0;
        int p1 = 0;
        int p2 = zeroPos.size() + onePos.size();

       	// Build permutation
        for (int i = 0; i < n; i++)
        {

            if (nums[i] < a)
            {
                perm[i] = p0++;
            }
            else if (nums[i] <= b)
            {
                perm[i] = zeroPos.size() + p1++;
            }
            else
            {
                perm[i] = p2++;
            }
        }

        long long ans = mergeSort(perm, 0, n - 1);

        return ans % MOD;
    }
};