class Solution {
public:
    int kthGrammar(int n, int k) {

        if (n == 1)
            return 0;

        int oldk = k;

        k = (k + 1) / 2;

        int ans = kthGrammar(n - 1, k);

        if (oldk % 2 == 0)
            return !ans;

        return ans;
    }
};