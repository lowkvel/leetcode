/*
    二维数组中的查找

    在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
    请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

    示例:
        现有矩阵 matrix 如下：
            [[1,   4,  7, 11, 15],
             [2,   5,  8, 12, 19],
             [3,   6,  9, 16, 22],
             [10, 13, 14, 17, 24],
             [18, 21, 23, 26, 30]]
        给定 target = 5，返回 true。
        给定 target = 20，返回 false。

    限制:   
        0 <= n <= 1000
        0 <= m <= 1000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int> >& matrix, int target) {
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++)
                if (matrix[i][j] == target)
                    return true;
        return false;
    }

    // linear search
    bool findNumberIn2DArray2(vector<vector<int> >& matrix, int target) {
        if (matrix.size() == 0)
            return false;

        // go from top-right corner
        int i = 0;
        int j = matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0) 
            if (target == matrix[i][j])
                return true;
            else if (target < matrix[i][j])
                j--;
            else
                i++;
        return false;

        // go from bottom-left corner is similar
        // ...
    }
};

int main() {

}