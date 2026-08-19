class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> pos;

        for(int i=0;i<boxes.size();i++){
            if(boxes[i]=='1')
                pos.push_back(i);
        }

        vector<int> ans(boxes.size(),0);

        for(int i=0;i<boxes.size();i++){
            for(auto x:pos)
                ans[i]+=abs(i-x);
        }

        return ans;
    }
};