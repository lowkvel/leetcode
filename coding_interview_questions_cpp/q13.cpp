/*
    13. 机器人的运动范围

    地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
    一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。
    例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

    示例 1：
        输入：m = 2, n = 3, k = 1
        输出：3

    示例 2：
        输入：m = 3, n = 1, k = 0
        输出：1

    提示：
        1 <= n,m <= 100
        0 <= k <= 20

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>
# include <queue>

using namespace std;

class Solution {
public:
    const int direction[2][2] = {{1, 0}, {0, 1}};       // only right and down is needed

    int digitCount(int x) {
        int ans = 0;
        while (x > 0) {
            ans = ans + x % 10;
            x = x / 10;
        }
        return ans;
    }

    // bfs with queue
    int movingCount(int m, int n, int k) {
        if (k <= 0)
            return 1;

        vector<vector<int> > grid(m, vector<int>(n, 0));
        queue<pair<int, int> > q;
        q.push(make_pair(0, 0));                                // push (0, 0) into queue
        grid[0][0] = 1;                                         // mark (0, 0) visited
        int ans = 1;
        while(!q.empty()) {
            for (int i = 0; i < 2; i++) {
                int nx = q.front().first + direction[i][0];     // nx calculation
                int ny = q.front().second + direction[i][1];    // ny calculation
                if (nx >= 0 && nx < m &&
                    ny >= 0 && ny < n &&
                    grid[nx][ny] == 0 &&
                    digitCount(nx) + digitCount(ny) <= k) {     // satisfy requirements
                        q.push(make_pair(nx, ny));
                        grid[nx][ny] = 1;
                        ans++;
                    }
            }
            q.pop();
        }

        return ans;
    }

    // iteration
    int movingCount2(int m, int n, int k) {
        if (k <= 0)
            return 1;

        vector<vector<int> > grid(m, vector<int>(n, 0));
        grid[0][0] = 1;
        int ans = 1;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if ((i == 0 && j == 0) || digitCount(i) + digitCount(j) > k)
                    continue;

                if (i - 1 >= 0)
                    grid[i][j] = grid[i][j] | grid[i - 1][j];
                if (j - 1 >= 0)
                    grid[i][j] = grid[i][j] | grid[i][j - 1];
                ans = ans + grid[i][j];
            }

        return ans;
    }
};

int main() {

}