class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        stations.push_back({target, 0});

        sort(stations.begin(), stations.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[0] < b[0];
             });

        priority_queue<int> pq;

        int fuel = startFuel;
        int currEnd = startFuel;
        int stops = 0, j = 0;
        int n = stations.size();

        while (currEnd < target) {
            while (j < n && stations[j][0] <= currEnd) {
                pq.push(stations[j][1]);
                j++;
            }

            if (pq.empty())
                return -1;

            fuel = pq.top();
            pq.pop();

            currEnd += fuel;
            stops++;
        }

        return stops;
    }
};