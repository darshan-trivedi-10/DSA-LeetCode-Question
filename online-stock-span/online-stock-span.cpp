class StockSpanner {
public:
    vector<int> prices;
    stack<int> s;
    StockSpanner() {        
        prices.push_back(1e6);
        s.push(0);
    }

    int next(int price) {
        while(price >= prices[s.top()]){
            s.pop();
        }
        int ans = prices.size() - s.top();
        s.push(prices.size());
        prices.push_back(price);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */