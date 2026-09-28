class Solution {
public:

    double bs(vector<int>& a, vector<int>& b, int l, int h) {
        int n = a.size();
        int m = b.size();

        int total = n + m;
        int left = (total + 1) / 2;

        while(l <= h) {

            int cntA = l + (h - l) / 2;
            int cntB = left - cntA;

            if(cntB < 0) {
                h = cntA - 1;
                continue;
            }

            if(cntB > m) {
                l = cntA + 1;
                continue;
            }

            int x1 = (cntA == 0) ? INT_MIN : a[cntA - 1];
            int x3 = (cntA == n) ? INT_MAX : a[cntA];

            int x2 = (cntB == 0) ? INT_MIN : b[cntB - 1];
            int x4 = (cntB == m) ? INT_MAX : b[cntB];

            if(x1 <= x4 && x2 <= x3) {

                if(total % 2 == 0)
                    return (max(x1, x2) + min(x3, x4)) / 2.0;

                return max(x1, x2);
            }

            else if(x1 > x4) {
                h = cntA - 1;
            }

            else {
                l = cntA + 1;
            }
        }

        return -1;
    }

    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {

        if(a.size() > b.size())
            swap(a, b);

        return bs(a, b, 0, a.size());
    }
};