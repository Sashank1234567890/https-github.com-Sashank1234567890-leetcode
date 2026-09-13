class Solution {
public:
    vector<int> lexicalOrder(int n) {

        deque<int> q;

        for (int i = 1; i <= 9 && i <= n; i++) {
            q.push_back(i);
        }

        vector<int> ans;

        while (!q.empty()) {

            int x = q.front();
            q.pop_front();

            ans.push_back(x);

            for (int i = 9; i >= 0; i--) {

                int child = x * 10 + i;

                if (child <= n) {
                    q.push_front(child);
                }
            }
        }

        return ans;
    }
};