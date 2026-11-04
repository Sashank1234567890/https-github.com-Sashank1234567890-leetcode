class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if (m > n)
            return -1;

        long long mod1 = 1000000007;
        long long mod2 = 1000000009;
        long long base = 31;

        long long hash1 = 0, hash2 = 0;
        long long pat1 = 0, pat2 = 0;

        long long power1 = 1, power2 = 1;

        for (int i = 0; i < m - 1; i++) {
            power1 = (power1 * base) % mod1;
            power2 = (power2 * base) % mod2;
        }

        for (int i = 0; i < m; i++) {
            pat1 = (pat1 * base + needle[i]) % mod1;
            pat2 = (pat2 * base + needle[i]) % mod2;

            hash1 = (hash1 * base + haystack[i]) % mod1;
            hash2 = (hash2 * base + haystack[i]) % mod2;
        }

        for (int i = 0; i <= n - m; i++) {

            if (hash1 == pat1 && hash2 == pat2) {
                if (haystack.compare(i, m, needle) == 0)
                    return i;
            }

            if (i < n - m) {
                hash1 = (base * (hash1 - haystack[i] * power1 % mod1 + mod1)
                         + haystack[i + m]) % mod1;

                hash2 = (base * (hash2 - haystack[i] * power2 % mod2 + mod2)
                         + haystack[i + m]) % mod2;
            }
        }

        return -1;
    }
};