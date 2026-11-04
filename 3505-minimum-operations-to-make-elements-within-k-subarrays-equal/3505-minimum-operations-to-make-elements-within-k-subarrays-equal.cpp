class Solution {
public:
    vector<int> med;
    vector<long long> cost;
    vector<vector<long long>> dp;

    long long solve(int i, vector<int>& nums, int& x, int k) {
        int n = nums.size();

        if (k == 0)
            return 0;

        if (i > n - x)
            return LLONG_MAX;

        if (dp[i][k] != -1)
            return dp[i][k];

        long long cnt = LLONG_MAX;

        cnt = min(cnt, solve(i + 1, nums, x, k));

        long long op = cost[i];

        long long next = solve(i + x, nums, x, k - 1);

        if (next != LLONG_MAX) {
            cnt = min(cnt, op + next);
        }

        return dp[i][k] = cnt;
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        auto comp = [](pair<int, int> a, pair<int, int> b) {
            return a < b;
        };

        set<pair<int, int>, decltype(comp)> mn(comp);
        set<pair<int, int>, decltype(comp)> mx(comp);

        med.clear();
        cost.clear();

        int n = nums.size();

        long long sumMn = 0, sumMx = 0;

        for (int i = 0; i < n; i++) {

            if (i >= x) {
                pair<int, int> p = {nums[i - x], i - x};

                auto it = mn.find(p);

                if (it != mn.end()) {
                    sumMn -= it->first;
                    mn.erase(it);
                }
                else {
                    it = mx.find(p);

                    if (it != mx.end()) {
                        sumMx -= it->first;
                        mx.erase(it);
                    }
                }
            }

            if (mn.empty()) {
                if (mx.empty() || mx.begin()->first >= nums[i]) {
                    mn.insert({nums[i], i});
                    sumMn += nums[i];
                }
                else {
                    mx.insert({nums[i], i});
                    sumMx += nums[i];
                }
            }
            else if (mn.rbegin()->first >= nums[i]) {
                mn.insert({nums[i], i});
                sumMn += nums[i];
            }
            else {
                mx.insert({nums[i], i});
                sumMx += nums[i];
            }

            if (mx.size() > mn.size()) {
                auto p = *mx.begin();

                mn.insert(p);
                sumMn += p.first;

                mx.erase(mx.begin());
                sumMx -= p.first;
            }
            else if (mn.size() > mx.size() + 1) {
                auto p = *mn.rbegin();

                mx.insert(p);
                sumMx += p.first;

                mn.erase(prev(mn.end())); //no method to delete last so use prev
                sumMn -= p.first;
            }

            if (i >= x - 1) {
                long long md = mn.rbegin()->first;

                med.push_back(md);

                // Calculate total operations using lower and upper sums
                long long op = 1LL * md * mn.size() - sumMn
                             + sumMx - 1LL * md * mx.size();

                cost.push_back(op);
            }
        }

        dp.assign(n + 1, vector<long long>(k + 1, -1));

        return solve(0, nums, x, k);
    }
};