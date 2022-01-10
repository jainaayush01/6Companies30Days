// Link:https://leetcode.com/problems/rotting-oranges/
class Solution
{
public:
    // dfs wont work as all rotten oranges will start rottening the fresh oranges adjacently
    // so we need to use bfs and do topological sort
    // firstly add all the elements in queue
    // for each element then add adjacent fresh elements to queue and remove the parent
    // increment ans and go on till queue is not empty
    vector<int> dirs = {0, 1, 0, -1, 0};

    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int min = 0, fresh = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    fresh++;
                }
                else if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty())
        {
            int qs = q.size();
            bool rotten = false;
            for (int i = 0; i < qs; i++)
            {
                auto elm = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k)
                {
                    int x = elm.first + dirs[k];
                    int y = elm.second + dirs[k + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1)
                    {
                        grid[x][y] = 2;
                        q.push({x, y});
                        fresh--;
                        rotten = true;
                    }
                }
            }
            if (rotten)
                min++;
        }
        return fresh ? -1 : min;
    }
};
