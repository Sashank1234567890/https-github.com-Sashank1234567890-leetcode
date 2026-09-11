class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& qr) {
        unordered_map<int, int> ballColor;
        unordered_map<int, int> colorCount;

        vector<int> ans;

        for (auto &q : qr) {
            int ball = q[0];
            int color = q[1];

          
            if (ballColor.find(ball) != ballColor.end()) {
                int oldColor = ballColor[ball];

                colorCount[oldColor]--;

                if (colorCount[oldColor] == 0)
                    colorCount.erase(oldColor);
            }

            
            ballColor[ball] = color;
            colorCount[color]++;

            ans.push_back(colorCount.size());
        }

        return ans;
    }
};