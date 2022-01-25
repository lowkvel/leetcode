/*
    48. 旋转图像

    给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
    你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

    示例 1：
        输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
        输出：[[7,4,1],[8,5,2],[9,6,3]]

    示例 2：
        输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
        输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
     
    提示：
        n == matrix.length == matrix[i].length
        1 <= n <= 20
        -1000 <= matrix[i][j] <= 1000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/rotate-image
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    // auxillary matrix
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> temp(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) 
                temp[j][n - i - 1] = matrix[i][j];  // m[i][j] -> m[j][n-i-1]

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                matrix[i][j] = temp[i][j];          // copy
    }

    // rotate 4 times
    void rotate2(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i)
            for (int j = 0; j < (n + 1) / 2; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
    }

    // flipping
    void rotate3(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // horizontal flip
        for (int i = 0; i < n / 2; ++i)
            for (int j = 0; j < n; ++j)
                swap(matrix[i][j], matrix[n - i - 1][j]);

        // diagonal flip
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                swap(matrix[i][j], matrix[j][i]);
    }
};

int main() {

}