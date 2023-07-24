class MedianFinder {
public:

    priority_queue<double> maxPQ; 
    priority_queue<double, vector<double>, greater<double>> minPQ;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int maxPQSize = maxPQ.size();
        int minPQSize = minPQ.size();

        if(minPQSize == maxPQSize){
            if(minPQSize == 0){
                minPQ.push(num);
            }else{
                int maxPQTopEle = maxPQ.top();
                if(maxPQTopEle > num){
                    minPQ.push(maxPQTopEle);
                    maxPQ.pop();
                    maxPQ.push(num);
                }else{
                    minPQ.push(num);
                }
            }
        }else{
            int minPQTopEle = minPQ.top();

            if(minPQTopEle > num){
                maxPQ.push(num);
            }else{
                // num > minPQTopEle
                minPQ.pop();
                minPQ.push(num);
                maxPQ.push(minPQTopEle);
            }
        }
    }
    
    double findMedian() {
        int size = maxPQ.size() + minPQ.size();
        if(size & 1){
            return minPQ.top();
        }else{
            return (minPQ.top() + maxPQ.top())/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */