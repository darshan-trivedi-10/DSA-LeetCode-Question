class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        const int n = mat.size();
        /*
        [0, 0] [0, m-1]
        [1, 1] [1, m-2]
        [2, 2] [3, m-3]
        [3, 3] 
        [4, 4]
        [5, 5]
        */

        int diagonal_sum = 0;
        for(int i =  0; i < n; i++){
            if(i == (n - i - 1)){
                diagonal_sum += mat[i][i];
                continue;
            }
            diagonal_sum += mat[i][i] + mat[i][n - i - 1];
        }

        return diagonal_sum;
    }
};