class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int, vector<int>> children;
        unordered_map<int, int> parent;

        for(int i = 0; i < n; i++) {
            int left = leftChild[i];
            int right = rightChild[i];

            if(left != -1) {
                children[i].push_back(left);

                if(parent.find(left) != parent.end())
                    return false;

                parent[left] = i;
            }

            if(right != -1) {
                children[i].push_back(right);

                if(parent.find(right) != parent.end())
                    return false;

                parent[right] = i;
            }
        }

        int root = -1;

        for(int i = 0; i < n; i++) {
            if(parent.find(i) == parent.end()) {
                if(root != -1)
                    return false;

                root = i;
            }
        }

        if(root == -1)
            return false;

        vector<bool> visited(n, false);
        queue<int> q;

        q.push(root);
        visited[root] = true;

        int count = 1;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int child : children[node]) {
                if(!visited[child]) {
                    visited[child] = true;
                    count++;
                    q.push(child);
                }
            }
        }

        return count == n;
    }
};