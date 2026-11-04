class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if (m > n)
            return -1;

        long long mod = 1e9 + 7;
        long long d = 256;

        long long hash1 = 0, hash2 = 0;
        long long power = 1;

        for (int i = 1; i < m ; i++) {
            power = (power * d) % mod;
        }

        for (int i = 0; i < m; i++) {
            hash1 = (hash1 * d + needle[i]) % mod;
            hash2 = (hash2 * d + haystack[i]) % mod;
        }

        for (int i = 0; i <= n - m; i++) {

            if (hash1 == hash2) {
                if (haystack.substr(i, m) == needle)
                    return i;
            }

            if (i < n - m) {
                hash2 = (d * (hash2 - haystack[i] * power % mod + mod) + haystack[i + m]) % mod;
            }
        }

        return -1;
    }
};