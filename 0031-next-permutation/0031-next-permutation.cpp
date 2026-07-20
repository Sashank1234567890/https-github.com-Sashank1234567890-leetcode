class Solution
{
    public:
        void nextPermutation(vector<int> &arr)
        {
            int n = arr.size();
            int idx = -1;

            for (int i = n - 2; i >= 0; i--)
            {
                if (arr[i] < arr[i + 1])
                {
                    idx = i;
                    break;
                }
            }

            if (idx == -1)
            {
                reverse(arr.begin(), arr.end());
                return;
            }

            int mnidx = lower_bound(arr.begin() + idx + 1,
                arr.end(),
                arr[idx],
                greater<int> ()) - arr.begin() - 1;

            swap(arr[idx], arr[mnidx]);

            reverse(arr.begin() + idx + 1, arr.end());
        }
};
