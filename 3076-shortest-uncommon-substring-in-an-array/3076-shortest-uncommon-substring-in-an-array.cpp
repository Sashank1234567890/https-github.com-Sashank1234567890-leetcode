class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {

        unordered_map<string_view, int> freq;

        for (string &s : arr) {

            unordered_set<string_view> seen;

            int n = s.size();

            for (int i = 0; i < n; i++) {
                for (int len = 1; i + len <= n; len++) {

                    string_view sub(s.data() + i, len);

                    if (!seen.count(sub)) {
                        seen.insert(sub);
                        freq[sub]++;
                    }
                }
            }
        }

        vector<string> ans;

        for (string &s : arr) {

            string best = "";

            int n = s.size();

            for (int i = 0; i < n; i++) {
                for (int len = 1; i + len <= n; len++) {

                    string_view sub(s.data() + i, len);

                    if (freq[sub] == 1) {

                        if (best.empty() ||
                            len < best.size() ||
                            (len == best.size() && sub < string_view(best))) {

                            best = string(sub);
                        }
                    }
                }
            }

            ans.push_back(best);
        }

        return ans;
    }
};