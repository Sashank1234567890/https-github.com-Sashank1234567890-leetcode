class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();

        vector<int> right(n, n);
        stack<int> st;

        // next smaller
        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if(!st.empty())
                right[i] = st.top();

            st.push(i);
        }

        vector<long long> dp(n, 0);

        long long ans = 0;
        int mod = 1e9 + 7;

        for(int i = n - 1; i >= 0; i--) {

            int j = right[i];

           
            dp[i] = 1LL * (j - i) * arr[i];

            
            if(j < n)
                dp[i] += dp[j];

            dp[i] %= mod;

            ans = (ans + dp[i]) % mod;
        }

        return ans;
    }
};