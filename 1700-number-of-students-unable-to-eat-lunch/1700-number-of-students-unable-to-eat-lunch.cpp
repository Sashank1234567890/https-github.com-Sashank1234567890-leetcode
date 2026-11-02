class Solution {
public:
    int countStudents(vector<int>& stu, vector<int>& san) {
        int n=san.size();
        queue<int>q;
        int j=0;
        for(int i=0;i<n;i++){
            if(san[j]!=stu[i]){
                q.push(i);
                continue;
            }
            j++;
        }
        vector<int>vis(n,0);
        while(j<n&&!q.empty()&&vis[q.front()]!=1){
            int idx=q.front();
            q.pop();
            if(san[j]!=stu[idx]){
                q.push(idx);
                vis[idx]=1;
                continue;

            }else{
                vis=vector<int>(n,0);
                j++;
            }
        }
   return q.size();}
};