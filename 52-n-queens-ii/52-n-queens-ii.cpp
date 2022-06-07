class Solution {
    
    void Solver(int n, int &totalAns,vector<string> &board, int col, vector<bool> &leftrow, vector<bool> &upperDiagnoal, vector<bool> &lowerDiagnoal){
        if(col==n){
            totalAns++;
            return;
        }
        
        for(int row = 0; row<n; row++){
            if(!leftrow[row] and !lowerDiagnoal[row+col] and !upperDiagnoal[n-1+col-row]){
                leftrow[row] = lowerDiagnoal[row+col] = upperDiagnoal[n-1+col-row] = true;
                board[row][col] = 'Q';
                Solver(n, totalAns, board, col+1, leftrow, upperDiagnoal, lowerDiagnoal);
                board[row][col] = '.';
                leftrow[row] = lowerDiagnoal[row+col] = upperDiagnoal[n-1+col-row] = false;   
            }
        }

    }
    
public:
    int totalNQueens(int n) {
        int totalAns = 0;
        string s(n,'.');
        vector<string> board(n,s);
        vector<bool> leftrow(n, false), upperDiagnoal(2*n-1, false), lowerDiagnoal(2*n-1, false); 
        Solver(n, totalAns, board, 0, leftrow, upperDiagnoal,lowerDiagnoal);
        return totalAns;

    }
};