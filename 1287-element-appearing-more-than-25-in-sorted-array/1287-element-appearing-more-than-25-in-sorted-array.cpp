class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int x1 = 0, x2 = 0, x3 = 0;
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;

        for (int x : arr) {
            if (x == x1)
                cnt1++;
            else if (x == x2)
                cnt2++;
            else if (x == x3)
                cnt3++;
            else if (cnt1 == 0) {
                x1 = x;
                cnt1 = 1;
            }
            else if (cnt2 == 0) {
                x2 = x;
                cnt2 = 1;
            }
            else if (cnt3 == 0) {
                x3 = x;
                cnt3 = 1;
            }
            else {
                cnt1--;
                cnt2--;
                cnt3--;
            }
        }

        cnt1 = cnt2 = cnt3 = 0;

        for (int x : arr) {
            if (x == x1)
                cnt1++;
            else if (x == x2)
                cnt2++;
            else if (x == x3)
                cnt3++;
        }

        int limit = arr.size() / 4;

        if (cnt1 > limit)
            return x1;
        if (cnt2 > limit)
            return x2;
        if (cnt3 > limit)
            return x3;

        return -1;
    }
};