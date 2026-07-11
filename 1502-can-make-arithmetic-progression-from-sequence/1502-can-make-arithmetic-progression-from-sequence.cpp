class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        
        unordered_set<int> st(begin(arr), end(arr));
        
        int min_el = *min_element(begin(arr), end(arr)); 
        int max_el = *max_element(begin(arr), end(arr)); 
        
        if((max_el - min_el)%(n-1))
            return false;
        
        int d = (max_el - min_el)/(n-1);
        
        int i = 0; 
       
        
        while(i < n) {
            int num = min_el + i*d;
            if(st.find(num) == st.end())
                return false;
            
            i++;
        }
        
        return true;
    }
};