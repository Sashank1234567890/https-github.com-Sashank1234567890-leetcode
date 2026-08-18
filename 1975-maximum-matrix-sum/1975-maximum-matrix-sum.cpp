class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int neg = 0;
        long long mn = LLONG_MAX;

        int n = matrix.size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] < 0)
                    neg++;

                sum += abs((long long)matrix[i][j]);

                mn = min(mn, abs((long long)matrix[i][j]));
            }
        }

        if(neg % 2 == 1)
            sum -= 2 * mn;

        return sum;
    }
};