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
        vector<vector<int>>ans;
        int start=-1;
        int end=-1;
        for(int x:st){
         if(start==-1){
            start=x;
            end=x;
         }else{
            if(x==end+1)
              end=x;
            else{
                ans.push_back({start,end});
                start=x;
                end=x;
            }  
         }

       
        }
        if(start!=-1)
         ans.push_back({start,end});
   return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */