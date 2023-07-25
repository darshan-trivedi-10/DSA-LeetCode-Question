class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        const int size = arr.size();

        int start = 0, end = size - 1;
        while(start <= end){
            int mid = (start + end)/2;

            if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]){
                start = mid;
                break;
            }else if(arr[mid] > arr[mid - 1]){
                start = mid + 1;
            }else if(arr[mid] > arr[mid + 1]){
                end = mid;
            }
        }

        return start;
    }
};

    //  5
    // 3  3
    //     2
    //      0
       