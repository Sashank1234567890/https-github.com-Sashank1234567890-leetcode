class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();

        vector<int> left(n, -1);
        vector<int> right(n, n);

        stack<int> st;

     
        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if(!st.empty())
                right[i] = st.top();

            st.push(i);
        }

        while(!st.empty())
            st.pop();

       
        for(int i = 0; i < n; i++) {

            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if(!st.empty())
                left[i] = st.top();

            st.push(i);
        }

        long long ans = 0;
        int mod = 1e9 + 7;

        for(int i = 0; i < n; i++) {

            long long l = i - left[i];
            long long r = right[i] - i;

            ans = (ans + l * r % mod * arr[i]) % mod;
        }

        return ans;
    }
};