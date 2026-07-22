class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        auto lambda = [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        };

        sort(points.begin(), points.end(), lambda);

        int cnt = 1;
        long long l = points[0][0];
        long long r = points[0][1];

        for (int i = 1; i < points.size(); i++) {

            if (points[i][0] <= r) {
               
                l = max(l, (long long)points[i][0]);
                r = min(r, (long long)points[i][1]);
            }
            else {
              
                cnt++;
                l = points[i][0];
                r = points[i][1];
            }
        }

        return cnt;
    }
};