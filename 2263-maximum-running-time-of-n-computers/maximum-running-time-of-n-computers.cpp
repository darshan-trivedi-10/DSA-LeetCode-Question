class Solution {

public:
    long long maxRunTime(int n, vector<int>& batteries) {
        const int size = batteries.size();
    
        long long start = 1;
        long long end = accumulate(batteries.begin(), batteries.end(),0LL)/n;

        while(start < end){
            long long mid = (start + end + 1)/2;
            long long time = 0;
            for(int t : batteries){
                time += min((long long)t, mid);
            }
            // 3 = ss
            if(mid*n <= time){
                start = mid;
            }else{
                end = mid - 1;
            }
            cout<<start<<" "<<end<<endl;
        }

        return start;
    }
};