class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        const int size = costs.size();
        int i = 0, j = size - 1;
        
        long long ans = 0;
        priority_queue<int, vector<int>, greater<int>> left, right;
        while(k--){
            while(left.size() < candidates && i <= j){
                left.push(costs[i]);
                i++;
            }

            while(right.size() < candidates && i <= j){
                right.push(costs[j]);
                j--;
            }

            int e1 = left.size() > 0 ? left.top() : INT_MAX;
            int e2 = right.size() > 0 ? right.top() : INT_MAX;

            if(e1 <= e2){
                ans += e1;
                left.pop();
            }else{
                ans += e2;
                right.pop();
            }
        }

        return ans;
    }
};