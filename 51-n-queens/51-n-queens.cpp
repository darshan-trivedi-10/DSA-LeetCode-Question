class Solution {
    
    void Solver(int n, vector<vector<string>> &ans, vector<string> &board, int col, vector<bool> &leftrow, vector<bool> &upperDiagnoal, vector<bool> &lowerDiagnoal){
        if(col==n){
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row<n; row++){
            if(!leftrow[row] and !lowerDiagnoal[row+col] and !upperDiagnoal[n-1+col-row]){
                leftrow[row] = lowerDiagnoal[row+col] = upperDiagnoal[n-1+col-row] = true;
                board[row][col] = 'Q';
                Solver(n, ans, board, col+1, leftrow, upperDiagnoal, lowerDiagnoal);
                board[row][col] = '.';
                leftrow[row] = lowerDiagnoal[row+col] = upperDiagnoal[n-1+col-row] = false;   
            }
        }

    }
    
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> board(n,s);
        vector<bool> leftrow(n, false), upperDiagnoal(2*n-1, false), lowerDiagnoal(2*n-1, false); 
        Solver(n, ans, board, 0, leftrow, upperDiagnoal,lowerDiagnoal);
        return ans;
    }
};