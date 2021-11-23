/*
    542. 01矩阵

    给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。
    两个相邻元素间的距离为 1 。

    示例 1：
        输入：mat = [[0,0,0],[0,1,0],[0,0,0]]
        输出：[[0,0,0],[0,1,0],[0,0,0]]

    示例 2：
        输入：mat = [[0,0,0],[0,1,0],[1,1,1]]
        输出：[[0,0,0],[0,1,0],[1,2,1]]
     
    提示：
        m == mat.length
        n == mat[i].length
        1 <= m, n <= 104
        1 <= m * n <= 104
        mat[i][j] is either 0 or 1.
        mat 中至少有一个 0

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/01-matrix
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>
# include <queue>

using namespace std;

class Solution {
public:
    const int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    // bfs with queue, with 2 auxilary matrixes
    vector<vector<int> > updateMatrix(vector<vector<int> >& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int> > distance(m, vector<int>(n));       // distance matrix
        vector<vector<int> > visited(m, vector<int>(n));        // visited matrix
        queue<pair<int, int> > q;

        // initialization, push all initial 0s into queue, mark them as visited
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] == 0) {
                    q.push(make_pair(i, j));
                    visited[i][j] = 1;                          // mark visited
                }

        // bfs
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {                       // loop through all 4 directions
                int nx = x + direction[i][0];
                int ny = y + direction[i][1];
                if (nx >= 0 && nx < m &&
                    ny >= 0 && ny < n &&
                    visited[nx][ny] == 0) {                     // within mat && not visited yet
                        q.push(make_pair(nx, ny));              // push into queue
                        distance[nx][ny] = distance[x][y] + 1;  // distance increment
                        visited[nx][ny] = 1;                    // mark visited
                    }
            }
        }

        return distance;
    }

    // bfs with queue, with 1 auxilary matrix but modified original mat
    vector<vector<int> > updateMatrix2(vector<vector<int> >& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int, int> > q;
        vector<vector<int> > visited(m, vector<int>(n));        // visited matrix

        // initialization, push all intial 0s into queue
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] == 0) {
                    q.push(make_pair(i, j));
                    visited[i][j] = 1;                          // mark visited
                }

        // bfs 
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + direction[i][0];
                int ny = y + direction[i][1];
                if (nx >= 0 && nx < m &&
                    ny >= 0 && ny < n &&
                    visited[nx][ny] == 0) {
                        q.push(make_pair(nx, ny));
                        mat[nx][ny] = mat[x][y] + 1;
                        visited[nx][ny] = 1;
                    }
            }
        }

        return mat;
    }

    // bfs with queue, without any auxilary matrix
    vector<vector<int> > updateMatrix3(vector<vector<int> >& mat) {

        return mat;
    }

    // dynamic programming, 4 directions
    vector<vector<int> > updateMatrix4(vector<vector<int> >& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int> > distance(m, vector<int>(n, INT_MAX - 1));

        // initialization
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) 
                if (mat[i][j] == 0)
                    distance[i][j] = 0;

        // dynamic programming. going from 1 to 0, hence 4 corner directions
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (i - 1 >= 0)
                    distance[i][j] = min(distance[i][j], distance[i - 1][j] + 1);   // from up
                if (j - 1 >= 0)
                    distance[i][j] = min(distance[i][j], distance[i][j - 1] + 1);   // from left
            }
        for (int i = m - 1; i >= 0; i--)
            for (int j = 0; j < n; j++) {
                if (i + 1 < m)
                    distance[i][j] = min(distance[i][j], distance[i + 1][j] + 1);   // from down
                if (j - 1 >= 0)
                    distance[i][j] = min(distance[i][j], distance[i][j - 1] + 1);   // from left
            }
        for (int i = 0; i < m; i++)
            for (int j = n - 1; j >= 0; j--) {
                if (i - 1 >= 0)
                    distance[i][j] = min(distance[i][j], distance[i - 1][j] + 1);   // from up
                if (j + 1 < n)
                    distance[i][j] = min(distance[i][j], distance[i][j + 1] + 1);   // from right
            }
        for (int i = m - 1; i >= 0; i--)
            for (int j = n - 1; j >= 0; j--) {
                if (i + 1 < m)
                    distance[i][j] = min(distance[i][j], distance[i + 1][j] + 1);   // from down
                if (j + 1 < n)
                    distance[i][j] = min(distance[i][j], distance[i][j + 1] + 1);   // from right
            }

        return distance;
    }

    // dynamic programming, 2 directions
    vector<vector<int> > updateMatrix5(vector<vector<int> >& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int> > distance(m, vector<int>(n, INT_MAX - 1));

        // initialization
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) 
                if (mat[i][j] == 0)
                    distance[i][j] = 0;

        // dynamic programming. going from 1 to 0, hence 4 corner directions
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (i - 1 >= 0)
                    distance[i][j] = min(distance[i][j], distance[i - 1][j] + 1);   // from up
                if (j - 1 >= 0)
                    distance[i][j] = min(distance[i][j], distance[i][j - 1] + 1);   // from left
            }
        for (int i = m - 1; i >= 0; i--)
            for (int j = n - 1; j >= 0; j--) {
                if (i + 1 < m)
                    distance[i][j] = min(distance[i][j], distance[i + 1][j] + 1);   // from down
                if (j + 1 < n)
                    distance[i][j] = min(distance[i][j], distance[i][j + 1] + 1);   // from right
            }

        return distance;
    }
};

int main() {

}