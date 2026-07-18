class MedianFinder {
    priority_queue<int> mx;
    priority_queue<int, vector<int>, greater<int>> mn;
    int sz;
public:
    MedianFinder() {
        sz = 0;
    }
    
    void addNum(int num) {
        if(mn.empty() || num > mn.top()) mn.push(num);
        else if(mx.empty() || num < mx.top()) mx.push(num);
        else if(mn.size() == mx.size()) mn.push(num);
        else mx.push(num);
        sz++;
        if(sz == 1) return;
        while(mx.size() < mn.size()-1){
            mx.push(mn.top());
            mn.pop();
        }
        while(mx.size() > mn.size()){
            mn.push(mx.top());
            mx.pop();
        }
    }
    
    double findMedian() {
        if(sz%2 == 1) return mn.top();
        double num = mx.top() + mn.top();
        num /= 2;
        return num;
    }
};
