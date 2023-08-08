class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) {
        int size = arr.size();
        vector<int> result(size);

        int i = 0, j = size - 1, k = size - 1;
        while(k >= 0){
            if(abs(arr[i]) > abs(arr[j])){
                result[k] = arr[i] * arr[i];
                i++;
            }else{
                result[k] = arr[j] * arr[j];
                j--;
            }
            k--;
        }

        return result;
    }
};