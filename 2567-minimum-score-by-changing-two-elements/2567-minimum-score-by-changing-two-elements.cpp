class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size();
        if(n<=3)
            return 0;

        vector<int> mn(3,INT_MAX),mx(3,INT_MIN);

        for(int x:nums) {
            for(int i=0;i<3;i++) {
                if(x<mn[i]) {
                    for(int j=2;j>i;j--)
                        mn[j]=mn[j-1];
                    mn[i]=x;
                    break;
                }
            }

            for(int i=0;i<3;i++) {
                if(x>mx[i]) {
                    for(int j=2;j>i;j--)
                        mx[j]=mx[j-1];
                    mx[i]=x;
                    break;
                }
            }
        }

        return min({
            mx[0]-mn[2],
            mx[1]-mn[1],
            mx[2]-mn[0]
        });
    }
};