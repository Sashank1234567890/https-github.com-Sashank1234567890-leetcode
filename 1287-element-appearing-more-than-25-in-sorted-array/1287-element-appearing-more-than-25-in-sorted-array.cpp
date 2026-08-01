class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();

        vector<int> idx = {0, n / 4, n / 2, 3 * n / 4};

        for (int i : idx) {
            int x = arr[i];

            int l = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
            int r = upper_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;

            if (r - l + 1 > n / 4)
                return x;
        }

        return -1;
    }
};