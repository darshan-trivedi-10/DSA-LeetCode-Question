class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        const int size = costs.size();
        long long ans = 0;

        if((candidates * 2) >= size){
            sort(costs.begin(), costs.end());
            for(int i = 0; i < k; i++){
                ans += costs[i];
            }
        }else{
            priority_queue<int, vector<int>, greater<int>> left, right;
            int i = 0, j = size - 1;
            while(k > 0 && i <= j){
                if(left.size() < candidates){
                    left.push(costs[i]);
                    i++;
                }

                if(right.size() < candidates){
                    right.push(costs[j]);
                    j--;
                } 

                if(left.size() == candidates && right.size() == candidates){
                    if(left.top() <= right.top()){
                        ans += left.top();
                        cout<<left.top()<<" ";
                        left.pop();
                        k--;
                    }else{
                        ans += right.top();
                        cout<<right.top()<<" ";
                        right.pop();
                        k--;
                    }
                }
            }

            if(k > 0){
                while(!right.empty()){
                    left.push(right.top());
                    right.pop();
                }
                while(k > 0){
                    ans += left.top();
                    left.pop();
                    k--;
                }
            }
        }

        return ans;
    }
};