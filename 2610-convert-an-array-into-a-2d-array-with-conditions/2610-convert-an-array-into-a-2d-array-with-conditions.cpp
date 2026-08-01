class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {

        vector<vector<int>> ans;
        unordered_map<int, unordered_set<int>> mp;

        for (int i = 0; i < nums.size(); i++) {

            if (ans.size() == 0) {
                ans.push_back(vector<int>());
                ans[0].push_back(nums[i]);
                mp[0].insert(nums[i]);
            }
            else {

                bool found = false;

                for (int j = 0; j < ans.size(); j++) {

                    if (!mp[j].contains(nums[i])) {
                        ans[j].push_back(nums[i]);
                        mp[j].insert(nums[i]);
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    ans.push_back(vector<int>());
                    ans.back().push_back(nums[i]);
                    mp[ans.size() - 1].insert(nums[i]);
                }
            }
        }

        return ans;
    }
};