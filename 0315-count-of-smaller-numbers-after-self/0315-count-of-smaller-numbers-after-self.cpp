class Solution {
public:
    void count(vector<pair<int,int>>& arr, int l, int r,
               vector<int>& ans, vector<pair<int,int>>& temp) {
        if (l >= r)
            return;

        int mid = l + (r - l) / 2;

        count(arr, l, mid, ans, temp);
        count(arr, mid + 1, r, ans, temp);

        int i = l, k = l, j = mid + 1;

        while (i <= mid && j <= r) {
            if (arr[i].first <= arr[j].first) {
              
                temp[k++] = arr[j++];
            }
            else {
                ans[arr[i].second] +=  r - j + 1;
                temp[k++] = arr[i++];
            }
        }

        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        while (j <= r) {
            temp[k++] = arr[j++];
        }

        for (int p = l; p <= r; p++) {
            arr[p] = temp[p];
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>> arr;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        vector<int> ans(n);
        vector<pair<int,int>> temp(n);

        count(arr, 0, n - 1, ans, temp);

        return ans;
    }
};