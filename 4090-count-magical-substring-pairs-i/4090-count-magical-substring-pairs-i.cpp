class Solution {
public:
    long long countMagicalPairs(string s) {
        int n = s.size();

        vector<vector<long long>> left(n, vector<long long>(27, 0));
        vector<vector<long long>> right(n, vector<long long>(27, 0));

        // Calculate number of substrings ending at i
        // having at most d distinct characters

        for (int d = 1; d <= 26; d++) {
            vector<int> freq(26, 0);

            int l = 0;
            int cnt = 0;

            for (int r = 0; r < n; r++) {
                int x = s[r] - 'a';

                if (freq[x] == 0) cnt++;
                freq[x]++;

                while (cnt > d) {
                    int y = s[l] - 'a';

                    freq[y]--;

                    if (freq[y] == 0) cnt--;

                    l++;
                }

                left[r][d] = r - l + 1;
            }
        }

        // Calculate number of substrings starting at i
        // having at most d distinct characters

        for (int d = 1; d <= 26; d++) {
            vector<int> freq(26, 0);

            int r = -1;
            int cnt = 0;

            for (int l = 0; l < n; l++) {

                while (r + 1 < n) {
                    int x = s[r + 1] - 'a';

                    if (freq[x] == 0 && cnt == d) break;

                    r++;

                    if (freq[x] == 0) cnt++;
                    freq[x]++;
                }

                right[l][d] = r - l + 1;

                int x = s[l] - 'a';

                freq[x]--;

                if (freq[x] == 0) cnt--;
            }
        }

        long long ans = 0;

        // Count magical pairs for every split
        for (int j = 0; j < n - 1; j++) {

            for (int d = 1; d <= 26; d++) {

                long long leftExact =
                    left[j][d] - left[j][d - 1];

                long long rightExact =
                    right[j + 1][d] - right[j + 1][d - 1];

                ans += leftExact * rightExact;
            }
        }

        return ans;
    }
};