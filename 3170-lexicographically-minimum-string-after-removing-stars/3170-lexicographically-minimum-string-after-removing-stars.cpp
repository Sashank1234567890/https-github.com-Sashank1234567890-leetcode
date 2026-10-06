class Solution
{
    public:
        typedef pair<char, int> P;
    struct Comp
    {
        bool operator()(P p, P q)
        {
            if (p.first == q.first)
                return p.second < q.second;

            return p.first > q.first;
        }
    };

    string clearStars(string s)
    {

        priority_queue<P, vector < P>, Comp> pq;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] != '*')
            {
                pq.push({ s[i],i });
            }
            else
            {
                pq.pop();
            }
        }
        string ans = "";
        unordered_set<int>st;
        while (!pq.empty())
        {
            st.insert(pq.top().second);
            pq.pop();
        }
        for(int i=0;i<n;i++){
            if(st.count(i))
            ans.push_back(s[i]);
        }
        return ans;
    }
};