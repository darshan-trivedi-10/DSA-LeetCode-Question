class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        const int size = arr.size();

        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum%3 != 0){
            return false;
        }

        int part = sum/3, ps = 0, cnt = 0;
        for(int element : arr){
            ps += element;
            if(ps == part){
                ps = 0;
                cnt++;
            }
        }
        return cnt >= 3;
    }
};