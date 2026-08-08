class Solution {
public:
    typedef pair<int,int> P;

    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        int n = times.size();

        int target = times[targetFriend][0];

        sort(times.begin(), times.end());

        set<int> st;

        for(int i = 0; i < n; i++)
            st.insert(i);

        priority_queue<P, vector<P>, greater<P>> pq;//{end,chair}

        for(vector<int> &v : times) {

            int arr = v[0];
            int dep = v[1];

            while(!pq.empty() && pq.top().first <= arr) {
                st.insert(pq.top().second);
                pq.pop();
            }

            int curr = *st.begin();
            st.erase(st.begin());

            if(arr == target)
                return curr;

            pq.push({dep, curr});
        }

        return -1;
    }
};