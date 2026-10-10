class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<pair<int,int>> vec;
        int n = nums1.size();

        for (int i = 0; i < n; i++) {
            vec.push_back({nums1[i], i});
        }

        sort(begin(vec), end(vec));

        vector<long long> ans(n, 0);
        long long val = 0;
        int i = 0;

        while (i < n) {
            int i_ = upper_bound(begin(vec), end(vec),make_pair(vec[i].first, INT_MAX)) - begin(vec);

            ans[vec[i].second] = val;

            for (int p = i; p < i_; p++) {
                ans[vec[p].second] = val;
            }

            for (int p = i; p < i_; p++) {
                pq.push(nums2[vec[p].second]);
                val += nums2[vec[p].second];

                if (pq.size() > k) {
                    val -= pq.top();
                    pq.pop();
                }
            }

            i = i_;
        }

        return ans;
    }
};