class Solution {

    bool is_safe(vector<string> &board, int row, int col){
        int n = board.size();
        for(int i = 0; i < n; i++){
            if(board[i][col] == 'Q' && i != row){
                return false;
            }
            if(board[row][i] == 'Q' && i != col){
                return false;
            }
        }

        int count = 0, i = row + 1, j = col - 1;
        while(i < n && j >= 0){
            if(board[i][j] == 'Q'){
                return false;
            }
            i++, j--;
        }

        i = row + 1, j = col + 1;
        while(i < n && j < n){
            if(board[i][j] == 'Q'){
                return false;
            }
            i++, j++;
        }
        
        i = row - 1, j = col - 1;

        while(i >= 0 && j >= 0){
            if(board[i][j] == 'Q'){
                return false;
            }
            i--, j--;
        }

        i = row - 1, j = col + 1;
        while(i >= 0 && j < n){
            if(board[i][j] == 'Q'){
                return false;
            }
            i--, j++;
        }

        return true;
    }

    void generate(int n, int row, vector<vector<string>> &boards, vector<string> &board){
        if(row == n){
            boards.push_back(board);
            return;
        }
       
        for(int col = 0; col < n; col++){
            board[row][col] = 'Q';
            if(is_safe(board, row, col)){
                generate(n, row + 1, boards, board);
            }
            board[row][col] = '.';
        }
    }    

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> boards;
        string s(n, '.');
        vector<string> board(n, s);
        generate(n, 0, boards, board);
        return boards;
    }
};