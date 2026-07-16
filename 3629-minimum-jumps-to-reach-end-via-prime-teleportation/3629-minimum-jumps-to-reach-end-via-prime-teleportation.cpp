class Solution {
public:

    int minJumps(vector<int>& nums) {

        int n = nums.size();

        int maxi = *max_element(nums.begin(), nums.end());

        // Smallest Prime Factor
        vector<int> spf(maxi + 1);

        for (int i = 0; i <= maxi; i++)
            spf[i] = i;

        for (int i = 2; i * i <= maxi; i++) {

            if (spf[i] == i) {

                for (int j = i * i; j <= maxi; j += i) {

                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }

       
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {

            int x = nums[i];

            while (x > 1) {

                int p = spf[x];

                mp[p].push_back(i);

                while (x % p == 0)
                    x /= p;
            }
        }

        queue<pair<int,int>> q;

        vector<int> vis(n, 0);

        q.push({0, 0});

        vis[0] = 1;

        while (!q.empty()) {

            auto [idx, steps] = q.front();
            q.pop();

            if (idx == n - 1)
                return steps;

            
            if (idx - 1 >= 0 && !vis[idx - 1]) {

                vis[idx - 1] = 1;
                q.push({idx - 1, steps + 1});
            }

           
            if (idx + 1 < n && !vis[idx + 1]) {

                vis[idx + 1] = 1;
                q.push({idx + 1, steps + 1});
            }

            int val = nums[idx];

           
            if (val > 1 && spf[val] == val) {

                for (int nxt : mp[val]) {

                    if (!vis[nxt]) {

                        vis[nxt] = 1;
                        q.push({nxt, steps + 1});
                    }
                }

                // process each prime only once
                mp[val].clear();
            }
        }

        return -1;
    }
};