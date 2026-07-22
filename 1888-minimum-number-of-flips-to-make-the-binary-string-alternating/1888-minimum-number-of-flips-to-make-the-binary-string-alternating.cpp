class Solution {
public:
    int minFlips(string s) {
        int n = s.size();

        string s1, s2;

        for(int i = 0; i < 2*n; i++) {
            s1 += (i % 2 ? '1' : '0');
            s2 += (i % 2 ? '0' : '1');
        }

        int i = 0, j = 0;
        int result1 = 0, result2 = 0;
        int ans = INT_MAX;

        while(j < 2*n) {

            if(s[j%n] != s1[j]) result1++;
            if(s[j%n] != s2[j]) result2++;

            if(j - i + 1 > n) {
                if(s[i%n] != s1[i]) result1--;
                if(s[i%n] != s2[i]) result2--;
                i++;
            }

            if(j - i + 1 == n)
                ans = min(ans, min(result1, result2));

            j++;
        }

        return ans;
    }
};