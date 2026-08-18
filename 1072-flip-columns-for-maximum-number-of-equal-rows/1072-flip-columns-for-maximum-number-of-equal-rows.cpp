class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_map<string, int> mp; 

        for(auto &row : matrix) { 
            string rowNature = "";

            int firstVal = row[0];
            for(int col = 0; col < n; col++) { 
                rowNature += (row[col] == firstVal) ? "S" : "B";
            }

            mp[rowNature]++;
        }

        int maxRows = 0;
        for(auto &it : mp) {
            maxRows = max(maxRows, it.second);
        }

        return maxRows;
    }
};

