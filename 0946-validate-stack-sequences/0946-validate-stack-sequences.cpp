class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int>spop;
        vector<int>spush;
        int i=0;
        for(int x:pushed){
            spush.push_back(x);
            while(!spush.empty()&&popped[i]==spush.back()){
                i++;
                spop.push_back(spush.back());
                spush.pop_back();
            }
        }
        while(!spush.empty()){
            spop.push_back(spush.back());
            spush.pop_back();
        }
         return spop==popped;
    }
};