class Solution {
public:
    int M = 1e9 + 7;
    vector<vector<vector<int>>> t;

    int solve(int zero, int one, int last, int limit) {

        if(t[zero][one][last] != -1)
            return t[zero][one][last];

        // Base cases
        if(one == 0) {
            if(last == 0 && zero <= limit)
                return t[zero][one][last] = 1;
            return t[zero][one][last] = 0;
        }

        if(zero == 0) {
            if(last == 1 && one <= limit)
                return t[zero][one][last] = 1;
            return t[zero][one][last] = 0;
        }

        if(last == 1) { // array ends with 1

            int ans = (solve(zero, one-1, 0, limit) +solve(zero, one-1, 1, limit)) % M;

            if(one-1 >= limit)
                ans = (ans - solve(zero, one-1-limit, 0, limit) + M) % M;

            return t[zero][one][1] = ans;
        }

        // array ends with 0
        int ans = (solve(zero-1, one, 0, limit) +solve(zero-1, one, 1, limit)) % M;

        if(zero-1 >= limit)
            ans = (ans - solve(zero-1-limit, one, 1, limit) + M) % M;

        return t[zero][one][0] = ans;
    }

    int numberOfStableArrays(int zero, int one, int limit) {

        t.assign(zero+1,vector<vector<int>>(one+1,vector<int>(2, -1)));

        return (solve(zero, one, 0, limit) +solve(zero, one, 1, limit)) % M;
    }
};