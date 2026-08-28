class Solution
{
    public:
        string decodeCiphertext(string encodedText, int rows)
        {
            if (rows == 1)
                return encodedText;

            int l = encodedText.size();
            int columns = l / rows;

            string originalText = "";

            vector<vector < char>> mat(rows, vector<char> (columns));

            int idx = 0;
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    mat[i][j] = encodedText[idx++];
                }
            }

            for (int col = 0; col < columns; col++)
            {
                int i = 0;
                int j = col;

                while (i < rows && j < columns)
                {
                    originalText += mat[i][j];
                    i++;
                    j++;
                }
            }

            while (!originalText.empty() && originalText.back() == ' ')
            {
                originalText.pop_back();
            }

            return originalText;
        }
};