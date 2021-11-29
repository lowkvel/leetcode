/*
    29. 顺时针打印矩阵

    输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

    示例 1：
        输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
        输出：[1,2,3,6,9,8,7,4,5]

    示例 2：
        输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
        输出：[1,2,3,4,8,12,11,10,9,5,6,7]
    
    限制：
        0 <= matrix.length <= 100
        0 <= matrix[i].length <= 100

    注意：本题与主站 54 题相同：https://leetcode-cn.com/problems/spiral-matrix/

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) 
            return {};
        
        int rowCount = matrix.size();
        int colCount = matrix[0].size();
        vector<vector<bool> > visited(rowCount, vector<bool>(colCount, false));
        int total = rowCount * colCount;
        vector<int> ans(total, 0);

        int x = 0;
        int y = 0;
        int directionIndex = 0;
        for (int i = 0; i < total; i++) {
            ans[i] = matrix[x][y];
            visited[x][y] = true;

            int nx = x + directions[directionIndex][0];
            int ny = y + directions[directionIndex][1];
            if (nx < 0 || nx >= rowCount || 
                ny < 0 || ny >= colCount || 
                visited[nx][ny]) {
                    directionIndex = (directionIndex + 1) % 4;
            }

            x = x + directions[directionIndex][0];
            y = y + directions[directionIndex][1];
        }

        return ans;
    }
};

int main() {

}
