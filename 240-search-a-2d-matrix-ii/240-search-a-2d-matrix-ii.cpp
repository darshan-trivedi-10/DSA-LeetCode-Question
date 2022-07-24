class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        
        int i = 0, j = m-1;
        
        while(i>=0 and i<n and j>=0 and j<m){
            if(matrix[i][j]==target){
                return true;
            }
            
            if(matrix[i][j]>target){
                j--;
            }else{
                i++;
            }
        }
        
        return false;
    }
};