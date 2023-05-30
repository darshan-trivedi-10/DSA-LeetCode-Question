class Solution
{
    bool isValid(vector<vector<char>> &board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == c || board[i][col] == c)
            {
                return false;
            }

            if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == c)
            {
                return false;
            }
        }
        
        return true;
    }

    bool Solve(vector<vector<char>> &board)
    {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char k = '1'; k <= '9'; k++)
                    {
                        if (isValid(board, i, j, k))
                        {
                            board[i][j] = k;
                            if (Solve(board) == true)
                            {
                                return true;
                            }
                            else
                            {
                                board[i][j] = '.';
                            }
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        Solve(board);
    }
};