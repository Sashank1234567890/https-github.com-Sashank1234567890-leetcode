class Solution {
public:
    int kthGrammar(int n, int k) {

        if(n == 1 && k == 1){
            return 0;
        }

        if(n == 2){
            return k % 2 == 0;
        }

        int val = 1 << (n - 1);

        if(k > val / 2){
            k = k - (val / 2);
            return !kthGrammar(n - 1, k);
        }
        else{
            return kthGrammar(n - 1, k);
        }
    }
};