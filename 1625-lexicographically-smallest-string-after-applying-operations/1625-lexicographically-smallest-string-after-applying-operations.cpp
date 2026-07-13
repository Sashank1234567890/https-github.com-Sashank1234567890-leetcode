class Solution {
public:
    void rotate(string &s, int b) {
        reverse(begin(s), end(s));
        reverse(begin(s), begin(s) + b);
        reverse(begin(s) + b, end(s));
    }

    void dfs(string curr, int a, int b, unordered_set<string> &visited, string &smallestString) {
        if (visited.count(curr)) return;
        visited.insert(curr);
        if (curr < smallestString) smallestString = curr;

        string added = curr;
        for (int i = 1; i < added.size(); i += 2)
            added[i] = ((added[i] - '0' + a) % 10) + '0';
        dfs(added, a, b, visited, smallestString);

        rotate(curr, b);
        dfs(curr, a, b, visited, smallestString);
    }

    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> visited;
        string smallestString = s;
        dfs(s, a, b, visited, smallestString);
        return smallestString;
    }
};