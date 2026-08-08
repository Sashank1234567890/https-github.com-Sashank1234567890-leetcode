class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        vector<vector<vector<int>>> groups;

        set<pair<int,int>> st;
        // {lastEnd, groupId}

        for (vector<int> &v : intervals) {

            int l = v[0];
            int r = v[1];

            auto it = st.lower_bound({l, -1});

            if (it == st.begin()) {

                int id = groups.size();
                groups.push_back({v});
                st.insert({r, id});
            }
            else {

                it--;

                int id = it->second;

                st.erase(it);

                groups[id].push_back(v);

                st.insert({r, id});
            }
        }

        return groups.size();
    }
};