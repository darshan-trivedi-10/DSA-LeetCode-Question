
struct node
{
    int x, y, time;
    node(int _x, int _y, int _time)
    {
        x = _x;
        y = _y;
        time = _time;
    }
};

class Solution
{
    bool isValid(int i, int j, int n, int m)
    {
        return (i >= 0 and j >= 0 and i < n and j < m);
    }

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        queue<node> q;
        int ans = 0;
        int rotton = 0, emp = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    rotton++;
                    node temp(i, j, 0);
                    q.push(temp);
                }
                else if (grid[i][j] == 0)
                {
                    emp++;
                }
            }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                node temp = q.front();
                q.pop();
                ans = max(ans, temp.time);
                for (int j = 0; j < 4; j++)
                {
                    int nx = temp.x + dx[j];
                    int ny = temp.y + dy[j];
                    if (isValid(nx, ny, n, m) and grid[nx][ny] == 1)
                    {
                        grid[nx][ny] = 2;
                        node dummy(nx, ny, temp.time + 1);
                        q.push(dummy);
                        rotton++;
                    }
                }
            }
        }
        
        if (rotton != (n * m) - emp)
        {
            ans = -1;
        }

        return ans;
    }
};
