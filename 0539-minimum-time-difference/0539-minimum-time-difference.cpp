class Solution
{
    public:
        int findMinDifference(vector<string> &timePoints)
        {
            int n = timePoints.size();
            vector<int> minutes(n);

            for (int i = 0; i < n; i++)
            {
                string time = timePoints[i];

                string hourSubstr = time.substr(0, 2);
                string minSubstr = time.substr(3);

                int hourInt = stoi(hourSubstr);
                int minInt = stoi(minSubstr);

                minutes[i] = hourInt *60 + minInt;
            }

            sort(begin(minutes), end(minutes));
            int result=INT_MAX;

            for (int i = 0; i < n; i++)
            {
                int diff = (minutes[(i + 1) % n] - minutes[i] + 1440) % 1440;
                result = min(result, diff);
            }

            return result;
        }
};