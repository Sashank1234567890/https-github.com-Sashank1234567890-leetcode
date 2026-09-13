class Solution {
public:
    vector<int> ans;

    void dfs(int x, int n) {
        if (x > n)
            return;

        ans.push_back(x);

        for (int i = 0; i <= 9; i++) {
            int next = x * 10 + i;

            if (next > n)
                return;

            dfs(next, n);
        }
    }

    vector<int> lexicalOrder(int n) {

        for (int i = 1; i <= 9; i++) {
            if (i > n)
                break;

            dfs(i, n);
        }

        return ans;
    }
};