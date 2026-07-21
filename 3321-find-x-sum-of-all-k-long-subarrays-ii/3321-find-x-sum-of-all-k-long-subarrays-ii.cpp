class Solution {
public:

    multiset<pair<int,int>> left, right;
    unordered_map<int,int> freq;
    long long sum = 0;

    void balance(int x){

        while(left.size() > x){

            auto it = left.begin();

            sum -= 1LL * it->first * it->second;
            right.insert(*it);
            left.erase(it);
        }

        while(left.size() < x && !right.empty()){

            auto it = prev(right.end());

            sum += 1LL * it->first * it->second;
            left.insert(*it);
            right.erase(it);
        }

        while(!left.empty() && !right.empty() &&
              *prev(right.end()) > *left.begin()){

            auto a = *left.begin();
            auto b = *prev(right.end());

            sum -= 1LL * a.first * a.second;
            sum += 1LL * b.first * b.second;

            left.erase(left.begin());
            right.erase(prev(right.end()));

            left.insert(b);
            right.insert(a);
        }
    }

    void add(pair<int,int> p,int x){

        if(left.empty() || p >= *left.begin()){
            left.insert(p);
            sum += 1LL * p.first * p.second;
        }
        else{
            right.insert(p);
        }

        balance(x);
    }

    void remove(pair<int,int> p,int x){

        auto it = left.find(p);

        if(it != left.end()){

            sum -= 1LL * it->first * it->second;
            left.erase(it);
        }
        else{

            it = right.find(p);
            if(it != right.end())
                right.erase(it);
        }

        balance(x);
    }

    vector<long long> findXSum(vector<int>& nums, int k, int x) {

        left.clear();
        right.clear();
        freq.clear();
        sum = 0;

        vector<long long> ans;

        int i = 0;

        for(int j = 0; j < nums.size(); j++){

            if(freq.count(nums[j]))
                remove({freq[nums[j]], nums[j]}, x);

            freq[nums[j]]++;

            add({freq[nums[j]], nums[j]}, x);

            if(j - i + 1 == k){

                ans.push_back(sum);

                remove({freq[nums[i]], nums[i]}, x);

                freq[nums[i]]--;

                if(freq[nums[i]] == 0)
                    freq.erase(nums[i]);
                else
                    add({freq[nums[i]], nums[i]}, x);

                i++;
            }
        }

        return ans;
    }
};