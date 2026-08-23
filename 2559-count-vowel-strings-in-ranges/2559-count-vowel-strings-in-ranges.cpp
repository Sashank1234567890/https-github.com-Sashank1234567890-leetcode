class Solution {
public:

    bool vowel(char c) {
        return c == 'a' || c == 'e' ||c == 'i' || c == 'o' ||c == 'u';
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        vector<int> v;

   
        for(int i = 0; i < words.size(); i++) {

            int n = words[i].size();

            if(vowel(words[i][0]) && vowel(words[i][n-1])) {

                v.push_back(i);
            }
        }

        vector<int> ans;

        for(auto q : queries) {

            int l = q[0];
            int r = q[1];

            int left = lower_bound(v.begin(), v.end(), l) - v.begin();

        
            int right = upper_bound(v.begin(), v.end(), r) - v.begin();

            ans.push_back(right - left);
        }

        return ans;
    }
};