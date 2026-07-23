class Solution {
public:
    bool isSubsequence(string s, string t) {

        unordered_map<char, vector<int>> pos;

        for (int i = 0; i < t.size(); i++)
            pos[t[i]].push_back(i);

        int prev = -1;

        for (char c : s) {

            if (pos.find(c) == pos.end())
                return false;

            auto &v = pos[c];

            auto it = upper_bound(v.begin(), v.end(), prev);

            if (it == v.end())
                return false;

            prev = *it;
        }

        return true;
    }
};