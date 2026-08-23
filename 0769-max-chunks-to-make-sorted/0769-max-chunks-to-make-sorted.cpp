class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        int n = arr.size();

        vector<int> suffixMin(n);

        suffixMin[n-1] = arr[n-1];

        for(int i = n-2; i >= 0; i--) {
            suffixMin[i] = min(arr[i], suffixMin[i+1]);
        }

        int ans = 0;
        int mx = INT_MIN;

        for(int i = 0; i < n; i++) {

            mx = max(mx, arr[i]);

            if(i == n-1 || mx < suffixMin[i+1]) {
                ans++;
            }
        }

        return ans;
    }
};