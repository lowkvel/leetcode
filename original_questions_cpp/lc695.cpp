/*
    695. 岛屿的最大面积

    给你一个大小为 m x n 的二进制矩阵 grid 。
    岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。
    你可以假设 grid 的四个边缘都被 0（代表水）包围着。

    岛屿的面积是岛上值为 1 的单元格的数目。
    计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。

    示例 1：
        输入：grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],
                     [0,0,0,0,0,0,0,1,1,1,0,0,0],
                     [0,1,1,0,1,0,0,0,0,0,0,0,0],
                     [0,1,0,0,1,1,0,0,1,0,1,0,0],
                     [0,1,0,0,1,1,0,0,1,1,1,0,0],
                     [0,0,0,0,0,0,0,0,0,0,1,0,0],
                     [0,0,0,0,0,0,0,1,1,1,0,0,0],
                     [0,0,0,0,0,0,0,1,1,0,0,0,0]]
        输出：6
        解释：答案不应该是 11 ，因为岛屿只能包含水平或垂直这四个方向上的 1 。

    示例 2：
        输入：grid = [[0,0,0,0,0,0,0,0]]
        输出：0
     
    提示：
        m == grid.length
        n == grid[i].length
        1 <= m, n <= 50
        grid[i][j] 为 0 或 1

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/max-area-of-island
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>
# include <queue>
# include <stack>

using namespace std;

class Solution {
public:
    const int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    // bfs with queue
    int maxAreaOfIsland(vector<vector<int> >& grid) {
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++) 
            for (int j = 0; j < grid[0].size(); j++) 
                if (grid[i][j] == 1) {
                    queue<pair<int, int> > q;
                    q.push(make_pair(i, j));
                    grid[i][j] = 0;
                    int tempArea = 1;
                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int nx = x + direction[k][0];
                            int ny = y + direction[k][1];
                            if (nx >= 0 && nx < grid.size() &&
                                ny >= 0 && ny < grid[0].size() &&
                                grid[nx][ny] == 1) {
                                    q.push(make_pair(nx, ny));
                                    grid[nx][ny] = 0;
                                    tempArea++;
                                }
                        }
                    }
                    maxArea = max(maxArea, tempArea);
                }
        return maxArea;
    }

    // bfs with recursion
    int maxAreaOfIsland2(vector<vector<int> >& grid) {

        return 0;
    }

    // dfs with stack
    int maxAreaOfIsland3(vector<vector<int> >& grid) {
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == 1) {
                    stack<pair<int, int> > s;
                    s.push(make_pair(i, j));
                    grid[i][j] = 0;
                    int tempArea = 1;
                    while (!s.empty()) {
                        int x = s.top().first;
                        int y = s.top().second;
                        s.pop();
                        for (int k = 0; k < 4; k++) {
                            int nx = x + direction[k][0];
                            int ny = y + direction[k][1];
                            if (nx >= 0 && nx < grid.size() &&
                                ny >= 0 && ny < grid[0].size() &&
                                grid[nx][ny] == 1) {
                                    s.push(make_pair(nx, ny));
                                    grid[nx][ny] = 0;
                                    tempArea++;
                                }
                        }
                    }
                    maxArea = max(maxArea, tempArea);
                }
        return maxArea;
    }

    // dfs with recursion
    int maxAreaOfIsland4(vector<vector<int> >& grid) {
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                maxArea = max(maxArea, maxAreaOfIsland4_dfs(grid, i, j));
        return maxArea;
    }

    int maxAreaOfIsland4_dfs(vector<vector<int> > &grid, int x, int y) {
        if (x < 0 || x >= grid.size() ||
            y < 0 || y >= grid[0].size() ||
            grid[x][y] != 1)
                return 0;
        
        int tempArea = 1;
        grid[x][y] = 0;
        for (int i = 0; i < 4; i++) 
            tempArea = tempArea + maxAreaOfIsland4_dfs(grid, x + direction[i][0], y + direction[i][1]);
        
        return tempArea;
    }
};

int main() {
    Solution *s = new Solution();

    vector<vector<int> > v;
    int a1[] = {0,0,1,0,0,0,0,1,0,0,0,0,0}; vector<int> v1(a1, a1 + 13); v.push_back(v1);
    int a2[] = {0,0,0,0,0,0,0,1,1,1,0,0,0}; vector<int> v2(a2, a2 + 13); v.push_back(v2);
    int a3[] = {0,1,1,0,1,0,0,0,0,0,0,0,0}; vector<int> v3(a3, a3 + 13); v.push_back(v3);
    int a4[] = {0,1,0,0,1,1,0,0,1,0,1,0,0}; vector<int> v4(a4, a4 + 13); v.push_back(v4);
    int a5[] = {0,1,0,0,1,1,0,0,1,1,1,0,0}; vector<int> v5(a5, a5 + 13); v.push_back(v5);
    int a6[] = {0,0,0,0,0,0,0,0,0,0,1,0,0}; vector<int> v6(a6, a6 + 13); v.push_back(v6);
    int a7[] = {0,0,0,0,0,0,0,1,1,1,0,0,0}; vector<int> v7(a7, a7 + 13); v.push_back(v7);
    int a8[] = {0,0,0,0,0,0,0,1,1,0,0,0,0}; vector<int> v8(a8, a8 + 13); v.push_back(v8);

    printf("%d\n", s->maxAreaOfIsland4(v));
}