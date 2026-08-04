class Solution {
public:
    vector<int> findMissingElements(vector<int>& arr) {
        auto [mn, mx] = minmax_element(arr.begin(), arr.end());

        int mnVal = *mn;
        int mxVal = *mx;

        vector<bool> vis(mxVal - mnVal + 1, false);

        for (int x : arr)
            vis[x - mnVal] = true;

        vector<int> ans;

        for (int i = 0; i < vis.size(); i++) {
            if (!vis[i])
                ans.push_back(i + mnVal);
        }

        return ans;
    }
};