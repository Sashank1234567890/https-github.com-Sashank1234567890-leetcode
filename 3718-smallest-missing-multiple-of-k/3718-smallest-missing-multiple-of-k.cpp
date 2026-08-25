class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        unordered_set<int> st;

        for(int x : nums)
            st.insert(x);

        int t = k;

        while(st.count(t))
            t += k;

        return t;
    }
};