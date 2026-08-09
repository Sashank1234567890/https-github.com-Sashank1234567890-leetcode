class Solution {
public:

    void update(vector<int>& bit, int i, int n, int val) {
        while(i <= n) {
            bit[i] += val;
            i += i & -i;
        }
    }

    int kth(vector<int>& bit, int n, int k) {
        int pos = 0;

        int p = 1;
        while((p << 1) <= n)
            p <<= 1;

        while(p > 0) {
            if(pos + p <= n && bit[pos + p] < k) {
                k -= bit[pos + p];
                pos += p;
            }

            p >>= 1;
        }

        return pos + 1;
    }

    int findTheWinner(int n, int m) {
        vector<int> bit(n + 1, 0);
        vector<int> ans;

        int i = 1;

        // Initially everyone is alive
        while(i <= n) {
            update(bit, i, n, 1);
            i++;
        }

        int index = 0;
        int left = n;

        while(left >= 1) {

            index = (index + m - 1) % left;

            // index is 0-based
            // Fenwick kth is 1-based
            int person = kth(bit, n, index + 1);

            ans.push_back(person);

            // Remove person
            update(bit, person, n, -1);

            left--;
        }

        return ans.back();
    }
};