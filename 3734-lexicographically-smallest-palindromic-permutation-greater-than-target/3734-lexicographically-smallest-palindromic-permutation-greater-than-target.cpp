class Solution {
public:
    string result = "";

    bool solve(string& curr, vector<int>& count, string& target, int i, bool greater, char middle) {

        int n = target.length();
\
        if(i == n / 2) {

            string ans = curr;

            if(n % 2 == 1)
                ans.push_back(middle);

            for(int j = curr.length() - 1; j >= 0; j--)
                ans.push_back(curr[j]);

            if(ans > target) {
                result = ans;
                return true;
            }

            return false;
        }

        for(char ch = 'a'; ch <= 'z'; ch++) {

           
            if(count[ch - 'a'] < 2)
                continue;

          
            if(greater == false && ch < target[i])
                continue;

            curr.push_back(ch);
            count[ch - 'a'] -= 2;

            bool isGreater = greater || ch > target[i];

            if(solve(curr, count, target,
                     i + 1, isGreater, middle))
                return true;

            curr.pop_back();
            count[ch - 'a'] += 2;
        }

        return false;
    }

    string lexPalindromicPermutation(string s, string target) {

        vector<int> count(26, 0);

        for(char ch : s)
            count[ch - 'a']++;

        int odd = 0;
        char middle = '#';

     
        for(int i = 0; i < 26; i++) {

            if(count[i] % 2 == 1) {
                odd++;
                middle = 'a' + i;
            }
        }

        if(odd > 1)
            return "";

        string curr;

        solve(curr, count, target, 0, false, middle);

        return result;
    }
};