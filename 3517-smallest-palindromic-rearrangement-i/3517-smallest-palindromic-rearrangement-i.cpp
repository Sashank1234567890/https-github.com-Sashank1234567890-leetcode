class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string left = "", mid = "";

        for (int i = 0; i < 26; i++) {
            int pairs = freq[i] / 2;
            left += string(pairs, char(i + 'a'));

            if (freq[i] % 2)
                mid = char(i + 'a');
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};