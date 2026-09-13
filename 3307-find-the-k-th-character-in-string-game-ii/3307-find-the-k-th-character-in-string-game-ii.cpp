class Solution {
public:
    char solve(long long k, vector<int>& operations, int i) {

        if (k == 1)
            return 'a';

        long long len = 1LL << (min(i,60));

        if (k <= len / 2)
            return solve(k, operations, i - 1);

        char res = solve(k - len / 2, operations, i - 1);

        if (operations[i - 1] == 1)
            res = (res == 'z') ? 'a' : res + 1;

        return res;
    }

    char kthCharacter(long long k, vector<int>& operations) {
        return solve(k, operations, operations.size());
    }
};