class Solution {
public:
    int minAddToMakeValid(string s) {

        int open = 0,close=0;
        int count=0;

        for(int i=0;i<s.size();i++)
        {
            
            if(s[i]=='(')
            open++;
           
            else
            {
             if(open)
             open--;
             else
             count++;
            }
        }


        for(int i=s.size()-1;i>=0;i--)
        {
            
            if(s[i]==')')
            close++;
           
            else
            {
             if(close)
             close--;
             else
             count++;
            }
        }

        return count;
    }
};