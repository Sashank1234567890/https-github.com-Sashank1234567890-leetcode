class Solution {
public:
    string smallestPalindrome(string s) {
        unordered_map<int, int> freq;

        for (char x : s)
            freq[x - 'a']++;

        string left = "", right = "", mid = "";

        for (int i = 0; i < 26; i++) {
            int pairs = freq[i] / 2;

            left += string(pairs, char(i + 'a'));
            right = string(pairs, char(i + 'a')) + right;

            if (freq[i] % 2)
                mid = char(i + 'a');
        }

        return left + mid + right;
    }
};