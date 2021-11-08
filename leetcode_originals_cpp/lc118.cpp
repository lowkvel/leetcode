/*
    118. 杨辉三角

    给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
    在「杨辉三角」中，每个数是它左上方和右上方的数的和。

    示例 1:
        输入: numRows = 5
        输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

    示例 2:
        输入: numRows = 1
        输出: [[1]]
     
    提示:
        1 <= numRows <= 30

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/pascals-triangle
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ans(numRows);
        for (int i = 0; i < numRows; ++i) {
            ans[i].resize(i + 1);               // resize each row into different size 
            ans[i][0] = 1;
            ans[i][i] = 1;
            for (int j = 1; j < i; ++j) 
                ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
        }
        return ans;
    }
};

int main() {

}