class Solution {
    
    bool isValid(int n, int m, int i, int j){
        return i>=0 and j>=0 and i<n and j<m;
    }
    
    int findPath(vector<vector<int>> &dp, int n, int m, int i, int j){
        if(i==n-1 || j==m-1){
            return 1;
        }
        
        if(isValid(n,m,i,j)==false){
            return false;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int downPath = findPath(dp,n,m,i+1,j);
        int rightPath = findPath(dp,n,m,i,j+1);
        
        return dp[i][j] = downPath + rightPath;
    }
    
    
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n, vector<int> (m,-1));
        return findPath(dp,n,m,0,0);
    }
};