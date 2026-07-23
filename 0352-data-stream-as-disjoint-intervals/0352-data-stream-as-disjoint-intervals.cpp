class SummaryRanges {
    map<int, int> intervals;

public:
    SummaryRanges() {}

    void addNum(int value) {

        int start = value;
        int end = value;

        auto nextInterval = intervals.upper_bound(value);

        if (nextInterval != intervals.begin()) {

            auto prevInterval = nextInterval;
            --prevInterval;

            // value already exists
            if (prevInterval->second >= value)
                return;

            // Merge with previous interval
            if (prevInterval->second + 1 == value) {
                start = prevInterval->first;
                intervals.erase(prevInterval);
            }
        }

        // Merge with next interval
        if (nextInterval != intervals.end() &&
            nextInterval->first == value + 1) {

            end = nextInterval->second;
            intervals.erase(nextInterval);
        }

        intervals[start] = end;
    }

    vector<vector<int>> getIntervals() {

        vector<vector<int>> ans;

        for (auto &[start, end] : intervals)
            ans.push_back({start, end});

        return ans;
    }
};
/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */