class Solution
{
    public:
        unordered_set<int> st;
    void cnt(vector<int> &dig, string &s, vector<int> &allow, int &ans)
    {
        if (s.size() == 3)
        {
            int num = stoi(s);
            if(num<100)
            return ;
            if(num%2)
            return ;
            if (!st.count(num))
            {   
                ans++;
                st.insert(num);
            }
            return;
        }
        for (int i = 0; i < dig.size(); i++)
        {
            if (allow[i])
            {
                allow[i] = 0;
                s.push_back(dig[i]+'0');
                cnt(dig, s, allow, ans);
                s.pop_back();
                allow[i] = 1;
            }
        }
    }
    int totalNumbers(vector<int> &dig)
    {
        string s = "";
        vector<int> allow(dig.size(), 1);
        int ans = 0;
        cnt(dig, s, allow, ans);
        return ans;
    }
};