class MyCalendar {
public:
    map<int,int> mp;

    MyCalendar() {

    }

    bool book(int s, int e) {

        auto it = mp.lower_bound(s);

       
        if(it != mp.end() && it->first < e)
            return false;

    
        if(it != mp.begin()) {

            it--;

            if(it->second > s)
                return false;
        }

        mp[s] = e;

        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */