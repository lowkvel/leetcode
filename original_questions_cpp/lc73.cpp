/*
    73. 矩阵置零

    给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

    示例 1：
        输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
        输出：[[1,0,1],[0,0,0],[1,0,1]]

    示例 2：
        输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
        输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
     

    提示：
        m == matrix.length
        n == matrix[0].length
        1 <= m, n <= 200
        -231 <= matrix[i][j] <= 231 - 1

    进阶：
        一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
        一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
        你能想出一个仅使用常量空间的解决方案吗？

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/set-matrix-zeroes
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    // (mn) space complexity
    void setZeroes(vector<vector<int> >& matrix) {
        vector<int> row(matrix.size());
        vector<int> col(matrix[0].size());

        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }

        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
                if (row[i] == 1 || col[j] == 1)
                    matrix[i][j] = 0;
    }

    // (1) space complexity, use 1st row/col of original matrix as auxiliary vectors in solution 1
    void setZeroes2(vector<vector<int> >& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int row_1st = 0;
        int col_1st = 0;

        // use 1st row/col of original matrix as auxiliary vectors in solution 1
        // but mark if 1st row/col contains 0 or not
        for (int i = 0; i < m; i++)
            if (matrix[i][0] == 0)
                col_1st = 1;
        for (int j = 0; j < n; j++)
            if (matrix[0][j] == 0)
                row_1st = 1;

        // update the rest
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
        
        // update 1st row/col
        if (col_1st == 1)
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        if (row_1st == 1)
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
    }
};

int main() {

}