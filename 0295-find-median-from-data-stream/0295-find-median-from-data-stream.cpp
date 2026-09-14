class MedianFinder {
public:
    priority_queue<int>left;
    priority_queue<int,vector<int>,greater<int>>right;
    int size;

    MedianFinder() {
        left= priority_queue<int>();
        right=priority_queue<int,vector<int>,greater<int>>();
        size=0;
    }
    
    void addNum(int num) {
        if(left.empty()||left.top()>num){
            left.push(num);
        }else{
            right.push(num);
        }
        size++;

        if(left.size()==right.size()+2){
            right.push(left.top());
            left.pop();
        }

        if(left.size()<right.size()){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(size%2){
            return left.top();
        }
        return (left.top()+right.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */