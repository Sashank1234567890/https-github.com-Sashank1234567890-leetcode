class StockSpanner
{
    public:
        stack<pair<int, int>> st;
    StockSpanner()
    { 
        st=stack<pair<int,int>>();
    }

    int next(int price)
    {
        int cnt = 0;
        while (!st.empty() && st.top().first <= price)
        {
            auto[x, y] = st.top();
            st.pop();
            cnt += y;
        }
        cnt++;
        st.push({ price,cnt });
        return cnt;
    }
};

/**
 *Your StockSpanner object will be instantiated and called as such:
 *StockSpanner* obj = new StockSpanner();
 *int param_1 = obj->next(price);
 */