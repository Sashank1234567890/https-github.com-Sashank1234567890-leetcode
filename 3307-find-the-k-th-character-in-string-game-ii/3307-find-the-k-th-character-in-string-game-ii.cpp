class Solution
{
    public:
        char kthCharacter(long long k, vector<int> &operations)
        {
           
            if (k == 1)
            {
                return 'a';
            }

            int n = operations.size();	
            int opType;	
            long long len = 1;	
            long long newK;	

           
            for (int i = 0; i < n; i++)
            {
                len *= 2;	
                if (len >= k)
                {
                	
                    opType = operations[i];	
                    newK = k - len / 2;	
                    break;	
                }
            }

           	
            char res = kthCharacter(newK, operations);

           	// If operation type is 0, return the character as is
            if (opType == 0)
                return res;

          
            if (res == 'z')
                return 'a';	// Handle wrap-around from 'z' to 'a'

            return res + 1;	
        }
};