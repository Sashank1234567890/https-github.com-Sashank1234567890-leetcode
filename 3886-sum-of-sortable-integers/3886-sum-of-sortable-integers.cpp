class Solution {
public:
    bool isRotation(vector<int>& vec1, vector<int>& vec2) {
        int n = vec1.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (vec1[i] > vec1[(i + 1) % n]) {
                count++;
                if (count > 1) return false;
            }
        }

        vector<int> temp = vec1;
        sort(temp.begin(), temp.end());

        return temp == vec2;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> div;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                div.push_back(i);
                if (i != n / i) div.push_back(n / i);
            }
        }

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int ans = 0;

        for (int i = 0; i < div.size(); i++) {
            int k = div[i];
            bool valid = 1;

            for (int j = 0; j < n; j += k) {
                int mn = INT_MAX, mx = INT_MIN;

                for (int l = j; l < j + k; l++) {
                    mn = min(mn, nums[l]);
                    mx = max(mx, nums[l]);
                }

                if (mn != sorted[j] || mx != sorted[j + k - 1]) {
                    valid = 0;
                    break;
                }

                vector<int> vec1(nums.begin() + j, nums.begin() + j + k);
                vector<int> vec2(sorted.begin() + j, sorted.begin() + j + k);

                if (!isRotation(vec1, vec2)) {
                    valid = 0;
                    break;
                }
            }

            if (valid) ans += k;
        }

        return ans;
    }
};