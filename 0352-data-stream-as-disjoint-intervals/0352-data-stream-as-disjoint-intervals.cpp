class SummaryRanges {
public:
    set<int>st;
    SummaryRanges() {
       st.clear();
    }
    
    void addNum(int value) {
       st.insert(value); 
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;

        for (int x : st) {

            if (ans.empty() || x > ans.back()[1] + 1) {
                ans.push_back({x, x});
            } else {
                ans.back()[1] = x;
            }
        }

        return ans;

    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */