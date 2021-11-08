/*
    566. 重塑矩阵

    在 MATLAB 中，有一个非常有用的函数 reshape ，它可以将一个 m x n 矩阵重塑为另一个大小不同（r x c）的新矩阵，但保留其原始数据。
    给你一个由二维数组 mat 表示的 m x n 矩阵，以及两个正整数 r 和 c ，分别表示想要的重构的矩阵的行数和列数。
    重构后的矩阵需要将原始矩阵的所有元素以相同的 行遍历顺序 填充。
    如果具有给定参数的 reshape 操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。

    示例 1：
        输入：mat = [[1,2],[3,4]], r = 1, c = 4
        输出：[[1,2,3,4]]

    示例 2：
        输入：mat = [[1,2],[3,4]], r = 2, c = 4
        输出：[[1,2],[3,4]]
    
    提示：
        m == mat.length
        n == mat[i].length
        1 <= m, n <= 100
        -1000 <= mat[i][j] <= 1000
        1 <= r, c <= 300

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/reshape-the-matrix
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    /*
        对于一个行数为 mm，列数为 nn，行列下标都从 0 开始编号的二维数组，
        我们可以通过下面的方式，将其中的每个元素 (i, j) 映射到整数域内，并且它们按照行优先的顺序一一对应着 [0, mn) 中的每一个整数。
        形象化地来说，我们把这个二维数组「排扁」成了一个一维数组。
        如果读者对机器学习有一定了解，可以知道这就是 flatten 操作。

        这样的映射即为：
            二维坐标(i, j) -> 一维坐标(i × n + j)
        同样地，我们可以将整数 x 的一维坐标映射回其在矩阵中的二维下标，即：
            i = x / n
            j = x % n

        那么题目需要我们做的事情相当于：
            先将二维数组映射成一个一维数组；
            再将这个一维数组映射回 r 行 c 列的二维数组。

        我们当然可以直接使用一个一维数组进行过渡，但我们也可以直接从二维数组得到 r 行 c 列的重塑矩阵：
            设 nums 本身为 m 行 n 列，如果 mn != rc，那么二者包含的元素个数不相同，因此无法进行重塑；
            否则，对于 x ∈ [0, mn)，第 x 个元素在 nums 中对应的下标为 (x / n,x % n)，而在新的重塑矩阵中对应的下标为 (x / c,x % c)。

        作者：LeetCode-Solution
        链接：https://leetcode-cn.com/problems/reshape-the-matrix/solution/zhong-su-ju-zhen-by-leetcode-solution-gt0g/
        来源：力扣（LeetCode）
        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    */
    vector<vector<int> > matrixReshape(vector<vector<int> >& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();

        if (m * n != r * c)    // incompatiable
            return mat;

        vector<vector<int> > ans(r, vector<int>(c));
        for (int x = 0; x < m * n; ++x)
            ans[x / c][x % c] = mat[x / n][x % n];

        return ans;
    }
};

int main() {

}
