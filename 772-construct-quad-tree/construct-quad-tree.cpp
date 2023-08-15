class Solution {

    bool isRoot(int row, int col, int n, vector<vector<int>> &grid){
        bool root = true;
        for(int i = row; i < row + n; i++){
            for(int j = col; j < col + n; j++){
                if(grid[i][j] != grid[row][col]){
                    root = false;
                    break;
                }
            }
        }

        return root;
    }

    Node* Helper(int row, int col, int n, vector<vector<int>> &grid){
        if(isRoot(row, col, n, grid)){
            return new Node(grid[row][col] == 1, 1, NULL, NULL, NULL, NULL);
        }
        
        Node* root = new Node(grid[row][col], 0, NULL, NULL, NULL, NULL);
        root->topLeft = Helper(row, col, n/2, grid);
        root->topRight = Helper(row, col + n/2, n/2, grid);
        root->bottomLeft = Helper(row + n/2, col, n/2, grid);
        root->bottomRight = Helper(row + n/2, col + n/2, n/2, grid);
        
        return root;    
    }


public:
    Node* construct(vector<vector<int>>& grid) {
        return Helper(0, 0, grid.size(), grid);        
    }
};