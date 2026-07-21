class Solution
{
    public:
        int countOverlaps(vector<vector < int>> &A, vector< vector< int>> &B, int rowOff, int colOff)
        {
            int n = A.size();
            int count = 0;

            // cout << "\n----------------------------\n";
            // cout << "Checking for rowOff = " << rowOff << ", collOff = " << colOff << endl;

            for (int row = 0; row < n; row++)
            {
                for (int col = 0; col < n; col++)
                {
                    if (row + rowOff < 0 || row + rowOff >= n || col + colOff < 0 || col + colOff >= n)
                        continue;

                    // cout << "A[" << row << "][" << col << "] = " << A[row][col] << ", ";
                    // cout << "B[" << row + rowOff << "][" << col + colOff << "] = " << B[row + rowOff][col + colOff] << endl;

                    count += A[row][col] *B[row + rowOff][col + colOff];//dono 1 tab count
                }
            }

                // cout<<"Count="<<count<<endl;
                // cout << "\n----------------------------\n";
          
            return count;
        }
    int largestOverlap(vector<vector < int>> &A, vector< vector< int>> &B)
    {
        int n = A.size();

        int maxOverlap = 0;

        for (int rowOff = -n + 1; rowOff < n; rowOff++)
        {
            for (int collOff = -n + 1; collOff < n; collOff++)
            {
                maxOverlap = max(maxOverlap, countOverlaps(A, B, rowOff, collOff));
            }
        }

        return maxOverlap;
    }
};