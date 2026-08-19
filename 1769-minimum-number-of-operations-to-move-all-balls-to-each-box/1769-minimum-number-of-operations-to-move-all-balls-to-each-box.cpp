class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();

        vector<int> left(n,0);
        vector<int> right(n,0);

        int balls=0;
        int moves=0;

        for(int i=0;i<n;i++){
            left[i]=moves;

            if(boxes[i]=='1')
                balls++;

            moves+=balls;
        }

        balls=0;
        moves=0;

        for(int i=n-1;i>=0;i--){
            right[i]=moves;

            if(boxes[i]=='1')
                balls++;

            moves+=balls;
        }

        for(int i=0;i<n;i++)
            left[i]+=right[i];

        return left;
    }
};