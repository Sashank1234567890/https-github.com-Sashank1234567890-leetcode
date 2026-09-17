class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int sum = 0;
        int i = 0;

        vector<pair<int,int>> len;

        // {start, length}
        for (int j = 0; j < n; j++) {
            sum += arr[j];

            while (i <= j && sum > target) {
                sum -= arr[i++];
            }

            if (sum == target) {
                len.push_back({i, j - i + 1});
            }
        }

        if (len.size() < 2) {
            return -1;
        }

        // Sort according to starting index
        ranges::sort(len);

        int m = len.size();

        // best[k] = minimum length among [0...k]
        vector<int> best(m);

        best[0] = len[0].second;

        for (int k = 1; k < m; k++) {
            best[k] = min(best[k - 1], len[k].second);
        }

        int ans = INT_MAX;

        for (int k = 0; k < m; k++) {
            int start = len[k].first;
            int length = len[k].second;

            int end = start + length - 1;

            // Find last interval whose end < start
            int low = 0;
            int high = k - 1;
            int pos = -1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                int prevStart = len[mid].first;
                int prevLength = len[mid].second;
                int prevEnd = prevStart + prevLength - 1;

                if (prevEnd < start) {
                    pos = mid;
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }

            if (pos != -1) {
                ans = min(ans, length + best[pos]);
            }
        }

        if (ans == INT_MAX) {
            return -1;
        }

        return ans;
    }
};