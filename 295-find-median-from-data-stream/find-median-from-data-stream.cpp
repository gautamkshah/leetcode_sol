class MedianFinder {
public:
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    int c = 0;
    MedianFinder() {}

    void addNum(int num) {
        if (c == 0) {
            pq1.push(num);
            c++;
            return;
        }
        int sz1 = pq1.size();
        int sz2 = pq2.size();
        if (sz1 == sz2) {
            if (pq2.top() >= num) {
                pq1.push(num);
            } else {
                int val = pq2.top();
                pq2.pop();
                pq1.push(val);
                pq2.push(num);
            }
        }else{
            pq1.push(num);
            int val=pq1.top();
            pq1.pop();
            pq2.push(val);
        }
        c++;
    }

    double findMedian() {
        if(c%2==1){
            return pq1.top();
        }else{
            double val1=pq1.top();
            double val2=pq2.top();
            return (val1+val2)/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */