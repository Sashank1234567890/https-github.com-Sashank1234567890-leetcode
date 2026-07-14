class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();

        int startZeros = 0;
        for(char &ch : s) {
            if(ch == '0')
                startZeros++;
        }

        if(startZeros == 0) {
            return 0; 
        }

        vector<int> operations(n+1, -1);
        //operations[z] = min operations required to reach state in which we have z 0s

        queue<int> que;
        que.push(startZeros);
        operations[startZeros] = 0;

        while(!que.empty()) {
            int z = que.front();
            que.pop();

            int minF = max(0, k-n+z);
            int maxF = min(k, z);

            for(int f = minF; f <= maxF; f++) {
                int newZ = z + k - 2*f;

                if(operations[newZ] == -1) {
                    operations[newZ] = operations[z] + 1;

                    if(newZ == 0) {
                        return operations[newZ];
                    }

                    que.push(newZ);
                }
            }
        }

        return -1;
    }
};

