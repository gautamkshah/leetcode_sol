class MedianFinder {
public:
    priority_queue<int> pq1;
    priority_queue<int,vector<int>, greater<int>> pq2;
    int sz1=0,sz2=0;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(sz2<sz1){
            if(!pq1.empty()){
                if(num>=pq1.top()){
                    pq2.push(num);
                    sz2++;
                }else{
                    int topp=pq1.top();
                    pq1.pop();
                    pq1.push(num);
                    pq2.push(topp);
                    sz2++;
                }
            }else{
                pq1.push(num);
                sz1++;
            }
        }
        else if(sz1==sz2){
            if(pq1.empty()) 
            pq1.push(num);
            else{
                int topp=pq2.top();
                if(num>topp){
                    pq2.pop();
                    pq2.push(num);
                    pq1.push(topp);
                }else{
                    pq1.push(num);
                }
            }
            sz1++;
        }
    }
    
    double findMedian() {
        int tot=sz1+sz2;
        if(tot%2==1){
            return pq1.top();
        }
            return ((double) pq1.top()+pq2.top())/2;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */