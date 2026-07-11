class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& points) {

        int x1 = points[0][0];
        int y1 = points[0][1];

        int x2 = points[1][0];
        int y2 = points[1][1];

        for(int i = 2; i < points.size(); i++) {

            int x = points[i][0];
            int y = points[i][1];

            if((long long)(y2-y1)*(x-x1) !=
               (long long)(y-y1)*(x2-x1))
                return false;
        }

        return true;
    }
};