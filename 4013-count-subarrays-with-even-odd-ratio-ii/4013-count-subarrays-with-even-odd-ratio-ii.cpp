class Solution
{
    public:
        vector<int> seg;

   	// seg[i] = frequency/count of prefix sums in this segment
    void update(int i, int l, int r, int pos)
    {
        if (l == r)
        {
            seg[i]++;
            return;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid) update(2*i + 1, l, mid, pos);
        else update(2*i + 2, mid + 1, r, pos);
        seg[i] = seg[2*i + 1] + seg[2*i + 2];
    }

     int query(int i, int l, int r, int ql, int qr)
    {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return seg[i];
        int mid = l + (r - l) / 2;
        return query(2*i + 1, l, mid, ql, qr) + query(2*i + 2, mid + 1, r, ql, qr);
    }
 

    long long countRatioSubarrays(vector<int> &nums, int a, int b)
    {
        int n = nums.size();

       	// odd = +a, even = -b
        vector < long long > pre(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2) pre[i + 1] = pre[i] + a;
            else pre[i + 1] = pre[i] - b;
        }

       	// Coordinate compression
        vector < long long > v = pre;
        sort(v.begin(), v.end());

        int m = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (i == 0 || v[i] != v[i - 1]) v[m++] = v[i];
        }
        v.resize(m);

       	// seg[i] stores frequency of prefix sums in its range
        seg.assign(4 *m, 0);

        long long ans = 0;

        for (long long x: pre)
        {
            int pos = lower_bound(v.begin(), v.end(), x) - v.begin();

           	// Count previous prefix sums <= current
            ans += query(0, 0, m - 1, 0, pos);

           	// Add current prefix sum
            update(0, 0, m - 1, pos);
        }

        return ans;
    }
};