class Solution
{
    bool isValid(int i, int j, int n, int m)
    {
        return (i >= 0 and j >= 0 and i < n and j < m);
    }
    int area(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited)
    {
        int n = grid.size(), m = grid[0].size();
        visited[i][j] = true;
        queue<pair<int, int>> q;
        q.push({i, j});
        int ans = 1;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int nx = dx[k] + temp.first;
                int ny = dy[k] + temp.second;
                if (isValid(nx, ny, n, m) and visited[nx][ny] == false and grid[nx][ny] == 1)
                {
                    ans++;
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }

        return ans;
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 and visited[i][j] == false)
                {
                    ans = max(ans, area(grid, i, j, visited));
                    cout << ans << endl;
                }
            }
        }

        return ans;
    }
};