class Solution {
public:
    void update(vector<int>& bit, int i, int n) {
        while (i <= n) {
            bit[i]++;
            i += i & -i;
        }
    }

    int query(vector<int>& bit, int i) {
        int ans = 0;

        while (i > 0) {
            ans += bit[i];
            i -= i & -i;
        }

        return ans;
    }

    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        unordered_map<int,int> mp;

        int idx = 1;
        for (int x : temp) {
            if (!mp.count(x)) {
                mp[x] = idx++;
            }
        }

        int sz = mp.size();

        vector<int> bit1(sz + 1), bit2(sz + 1);
        vector<int> a, b;

        a.push_back(nums[0]);
        b.push_back(nums[1]);

        update(bit1, mp[nums[0]], sz);
        update(bit2, mp[nums[1]], sz);

        for (int i = 2; i < n; i++) {
            int id = mp[nums[i]];

            int g1 = a.size() - query(bit1, id);
            int g2 = b.size() - query(bit2, id);

            if (g1 > g2) {
                a.push_back(nums[i]);
                update(bit1, id, sz);
            }
            else if (g2 > g1) {
                b.push_back(nums[i]);
                update(bit2, id, sz);
            }
            else {
                if (a.size() <= b.size()) {
                    a.push_back(nums[i]);
                    update(bit1, id, sz);
                }
                else {
                    b.push_back(nums[i]);
                    update(bit2, id, sz);
                }
            }
        }

        a.insert(a.end(), b.begin(), b.end());
        return a;
    }
};