class Solution
{
    public:
        char nextGreatestLetter(vector<char> &letters, char target)
        {
            auto it = upper_bound(begin(letters), end(letters), target);
            return it == letters.end() ? letters[0] : *it;
        }
};