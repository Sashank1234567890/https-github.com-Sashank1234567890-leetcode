class Solution {
public:

    bool solve(int idx, string &word,
               unordered_set<string> &st,
               vector<int> &dp) {

        if (idx == word.size())
            return true;

        if (dp[idx] != -1)
            return dp[idx];

        string cur = "";

        for (int i = idx; i < word.size(); i++) {

            cur += word[i];

            if (st.count(cur) &&
                solve(i + 1, word, st, dp))
                return dp[idx] = true;
        }

        return dp[idx] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {

        unordered_set<string> st(words.begin(), words.end());
        vector<string> ans;

        for (string &word : words) {

            st.erase(word);

            vector<int> dp(word.size(), -1);

            if (solve(0, word, st, dp))
                ans.push_back(word);

            st.insert(word);
        }

        return ans;
    }
};