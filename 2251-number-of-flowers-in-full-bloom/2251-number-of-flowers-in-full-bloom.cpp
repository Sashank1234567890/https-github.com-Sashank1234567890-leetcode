class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {

        map<int, int> diff;

        for(auto &f : flowers) {
            diff[f[0]]++;
            diff[f[1] + 1]--;
        }

        vector<pair<int,int>> queries;

        for(int i = 0; i < people.size(); i++) {
            queries.push_back({people[i], i});
        }

        sort(queries.begin(), queries.end());

        vector<int> ans(people.size());

        int bloom = 0;

        auto it = diff.begin();

        for(auto &[time, idx] : queries) {

            while(it != diff.end() && it->first <= time) {
                bloom += it->second;
                it++;
            }

            ans[idx] = bloom;
        }

        return ans;
    }
};