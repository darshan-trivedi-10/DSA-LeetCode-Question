class Solution {

    long calc(long n){
        return ((n * (n + 1)) / 2);;
    }


    long getSum(int totalLen, int val){
        long totalSum = 0;
        int decreasingLen = val;

        if(totalLen >= decreasingLen){
            long currSum = calc(val);
            int remainingSum = totalLen - decreasingLen;
            totalSum = currSum + remainingSum;
        }else{
            long lastVal = decreasingLen - totalLen;
            totalSum = calc(val) - calc(lastVal);
        }

        return totalSum;
    }


public:
    int maxValue(int n, int index, int maxSum) {

        int start = 1, end = maxSum, ans = -1;

        int leftCount = index, rightCount = n - index - 1;

        while(start <= end){
            int mid = start + (end-start)/2;
            
            long leftSum = getSum(leftCount, mid - 1);
            long rightSum = getSum(rightCount, mid - 1);
            long totalSum = leftSum + mid + rightSum;
                      
            if(totalSum > maxSum){
                end = mid - 1;
            }else{
                ans = mid;
                start = mid + 1;
            }
        }

        return ans;
    }
};