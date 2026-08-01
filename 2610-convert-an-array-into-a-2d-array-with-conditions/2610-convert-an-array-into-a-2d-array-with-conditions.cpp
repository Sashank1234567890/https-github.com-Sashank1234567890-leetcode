class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {

        unordered_map<int, int> freq;
        vector<vector<int>> ans;

        for (int x : nums) {

            if (freq[x] == ans.size())
                ans.push_back({});

            ans[freq[x]].push_back(x);
            freq[x]++;
        }

        return ans;
    }
};