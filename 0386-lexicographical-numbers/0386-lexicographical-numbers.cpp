class Solution {
public:
    vector<int> lexicalOrder(int n) {
       deque<int>q;
       for(int i=1;i<=9;i++){
        q.push_back(i);
       } 
       vector<int>ans;
       while(!q.empty()){
        int x=q.front();
        q.pop_front();
        if(x>n)
        continue;
        ans.push_back(x);
        for(int i=9;i>=0;i--){
            q.push_front(x*10+i);
        }
       }
   return ans; }
};