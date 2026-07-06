class Solution
{
    public:
        int removeCoveredIntervals(vector<vector < int>> &intervals)
        {
            int n = intervals.size();
            sort(intervals.begin(), intervals.end(), [](auto &a, auto &b)
            {
                if (a[0] == b[0])
                    return a[1] > b[1];
                return a[0] < b[0];
	});
            int result = 1;

            int first = intervals[0][0];
            int second = intervals[0][1];

            for (int i = 1; i < n; i++)
            {

                int l = intervals[i][0];
                int r = intervals[i][1];

                if (l >= first && r <= second)
                {

                    continue;
                }

                result++;
                first = l;
                second = r;
            }

            return result;
        }
};