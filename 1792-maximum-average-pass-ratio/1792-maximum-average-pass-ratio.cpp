class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,int>> pq;

        for(int i = 0; i < classes.size(); i++) {
            double p = classes[i][0];
            double t = classes[i][1];

            double ratio = (p + 1) / (t + 1) - p / t;

            pq.push({ratio, i});
        }

        while(extraStudents--) {
            auto [gain, i] = pq.top();
            pq.pop();

            classes[i][0]++;
            classes[i][1]++;

            double p = classes[i][0];
            double t = classes[i][1];

            double newGain = (p + 1) / (t + 1) - p / t;

            pq.push({newGain, i});
        }

        double ans = 0;

        for(auto &x : classes)
            ans += (double)x[0] / x[1];

        return ans / classes.size();
    }
};