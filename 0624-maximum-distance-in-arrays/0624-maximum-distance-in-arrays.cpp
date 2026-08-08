class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        set<pair<int,int>> st;

        for (int i = 0; i < arrays.size(); i++) {
            st.insert({arrays[i][0], i});
            st.insert({arrays[i].back(), i});
        }

        auto mn = st.begin();
        auto mx = prev(st.end());

        if (mn->second != mx->second)
            return mx->first - mn->first;

        auto mn2 = next(mn);
        auto mx2 = prev(mx);

        return max(mx->first - mn2->first,
                   mx2->first - mn->first);
    }
};