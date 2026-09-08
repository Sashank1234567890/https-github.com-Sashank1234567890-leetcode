class Solution
{
    public:
        vector<bool> validSubarrays(vector<int> &nums, int k, vector<vector< int>> &queries)
        {

            int n = nums.size();
            int q = queries.size();

           	// Coordinate compression
            vector<int> values = nums;
            sort(values.begin(), values.end());
            values.erase(unique(values.begin(), values.end()), values.end());

            for (int &x: nums)
            {
                x = lower_bound(values.begin(), values.end(), x) - values.begin();
            }

           	// Store queries as {l, r, index}
            vector<array<int, 3>> qs;

            for (int i = 0; i < q; i++)
            {
                qs.push_back({ queries[i][0],queries[i][1],i });
            }

           	// Mo's block size
            int block = sqrt(n);

            sort(qs.begin(), qs.end(),
               [& ](auto &a, auto &b)
                {
                    int blockA = a[0] / block;
                    int blockB = b[0] / block;

                    if (blockA != blockB)
                        return blockA < blockB;

                   	// Zig-zag ordering reduces movement
                    if (blockA & 1)
                        return a[1] > b[1];

                    return a[1] < b[1];
	});

            vector<int> freq(values.size(), 0);

            int distinct = 0;
            int odd = 0;

            auto add =[& ](int x)
            {
                if (freq[x] == 0)
                {
                    distinct++;
                }

               	// Before increasing:
               	// even -> odd : odd increases
               	// odd -> even : odd decreases
                if (freq[x] % 2 == 0)
                    odd++;
                else
                    odd--;

                freq[x]++;
            };

            auto remove =[& ](int x)
            {
               	// Before decreasing:
               	// odd -> even : odd decreases
               	// even -> odd : odd increases
                if (freq[x] % 2 == 0)
                    odd++;
                else
                    odd--;

                freq[x]--;

                if (freq[x] == 0)
                {
                    distinct--;
                }
            };

            vector<bool> ans(q);

            int L = 0;
            int R = -1;

            for (auto &[l, r, idx]: qs)
            {

                while (L > l)
                {
                    L--;
                    add(nums[L]);
                }

                while (R < r)
                {
                    R++;
                    add(nums[R]);
                }

                while (L < l)
                {
                    remove(nums[L]);
                    L++;
                }

                while (R > r)
                {
                    remove(nums[R]);
                    R--;
                }

                ans[idx] = (distinct == k && odd == 0);
            }

            return ans;
        }
};