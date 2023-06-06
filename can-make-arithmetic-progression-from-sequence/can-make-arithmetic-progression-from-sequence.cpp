class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        const int size = arr.size();
        sort(arr.begin(), arr.end());

        bool isAP = true;
        for(int i = 2; i < size; i++){
            if(arr[i-1] - arr[i] != arr[i-2] - arr[i-1]){
                return false;
            }
        }

        return true;
    }
};