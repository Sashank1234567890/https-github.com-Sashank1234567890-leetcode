class Solution {
public:
    bool buddyStrings(string s, string goal) {

        if (s.size() != goal.size())
            return false;

        vector<int> diff;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] != goal[i])
                diff.push_back(i);

            if (diff.size() > 2)
                return false;
        }

        if (diff.size() == 2) {

            int i = diff[0];
            int j = diff[1];

            return s[i] == goal[j] && s[j] == goal[i];
        }

        if (diff.size() == 1)
            return false;

        
        vector<int> freq(26, 0);

        for (char c : s) {

            freq[c - 'a']++;

            if (freq[c - 'a'] > 1)//acca goal acca swap aa or cc
                return true;
        }

        return false;
    }
};