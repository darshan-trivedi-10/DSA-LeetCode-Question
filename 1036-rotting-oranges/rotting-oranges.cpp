struct node{
    int x, y, time;
    node(int _x,int _y,int _time){
        x = _x, y = _y, time = _time;
    }
};

class Solution {
    bool isValid(int i, int j, int n, int m)
    {
        return (i >= 0 and j >= 0 and i < n and j < m);
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), cnt = 0, rotten = 0;
        queue<node> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    node temp(i, j, 0);
                    q.push(temp);
                }else if(grid[i][j] == 1){
                    cnt++;
                }
            }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        int ans = 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            ans = max(ans, it.time);

            for(int j = 0; j < 4; j++){
                int nx = it.x + dx[j], ny = it.y + dy[j];
                if(isValid(nx, ny, n, m) && grid[nx][ny] == 1){
                    grid[nx][ny] = 2;
                    node temp(nx, ny, it.time + 1);
                    q.push(temp);
                    rotten++;
                }
            }

        }

        if(rotten != cnt){
            ans = -1;
        }

        return ans;
    }
};