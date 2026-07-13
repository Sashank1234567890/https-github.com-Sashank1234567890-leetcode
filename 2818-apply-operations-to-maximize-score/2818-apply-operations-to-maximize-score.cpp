class Solution {
public:
    const int MOD = 1e9 + 7;

    long long findPower(long long a, long long b) {
        if (b == 0) return 1;
        long long half = findPower(a, b / 2);
        long long ans = (half * half) % MOD;
        if (b & 1)
            ans = (ans * a) % MOD;
        return ans;
    }

    vector<int> findPrimeScores(vector<int>& nums) {

        int n = nums.size();
        vector<int> primeScores(n);

        int mx = *max_element(nums.begin(), nums.end());

        vector<int> spf(mx + 1);

        for (int i = 0; i <= mx; i++)
            spf[i] = i;

        for (int i = 2; i * i <= mx; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= mx; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }

        for (int i = 0; i < n; i++) {

            int num = nums[i];

            while (num > 1) {

                int p = spf[num];
                primeScores[i]++;

                while (num % p == 0)
                    num /= p;
            }
        }

        return primeScores;
    }

    vector<int> findNextGreater(vector<int>& primeScores) {

        int n = primeScores.size();

        vector<int> nextGreater(n, n);

        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && primeScores[st.top()] <= primeScores[i])
                st.pop();

            if (!st.empty())
                nextGreater[i] = st.top();

            st.push(i);
        }

        return nextGreater;
    }

    vector<int> findPrevGreater(vector<int>& primeScores) {

        int n = primeScores.size();

        vector<int> prevGreater(n, -1);

        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && primeScores[st.top()] < primeScores[i])
                st.pop();

            if (!st.empty())
                prevGreater[i] = st.top();

            st.push(i);
        }

        return prevGreater;
    }

    int maximumScore(vector<int>& nums, int k) {

        vector<int> primeScores = findPrimeScores(nums);

        vector<int> nextGreater = findNextGreater(primeScores);

        vector<int> prevGreater = findPrevGreater(primeScores);

        int n = nums.size();

        vector<long long> subarrays(n);

        for (int i = 0; i < n; i++)
            subarrays[i] = 1LL * (nextGreater[i] - i) * (i - prevGreater[i]);

        vector<pair<int, int>> sortedNums;

        for (int i = 0; i < n; i++)
            sortedNums.push_back({nums[i], i});

        sort(sortedNums.begin(), sortedNums.end(), greater<>());

        long long score = 1;

        int idx = 0;

        while (k > 0) {

            auto [num, i] = sortedNums[idx];

            long long ops = min(1LL * k, subarrays[i]);

            score = (score * findPower(num, ops)) % MOD;

            k -= ops;
            idx++;
        }

        return score;
    }
};