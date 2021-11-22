/*
    12. 矩阵中的路径

    给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。
    如果 word 存在于网格中，返回 true ；否则，返回 false 。
    单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
    同一个单元格内的字母不允许被重复使用。

    例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。
        A B C E
        S F C S
        A D E E

    示例 1：
        输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
        输出：true

    示例 2：
        输入：board = [["a","b"],["c","d"]], word = "abcd"
        输出：false
    
    提示：
        1 <= board.length <= 200
        1 <= board[i].length <= 200
        board 和 word 仅由大小写英文字母组成

    注意：本题与主站 79 题相同：https://leetcode-cn.com/problems/word-search/

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    const int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    bool exist(vector<vector<char> >& board, string word) {
        if (board.size() == 0 || board[0].size() == 0 || word == "")
            return false;

        for (int i = 0; i < board.size(); i++) 
            for (int j = 0; j < board[0].size(); j++) 
                if (board[i][j] == word[0])
                    if (dfs(board, word, i, j, 0) == true) 
                        return true;

        return false;
    }

    bool dfs(vector<vector<char> > &board, string word, int x, int y, int p) {
        if (x < 0 || x >= board.size() ||                   // exceptions
            y < 0 || y >= board[0].size() || 
            board[x][y] != word[p])
                return false;

        if (p == word.size() - 1)                           // char matched from above, now it is the only char left
            return true;                                    // return true;

        board[x][y] = '.';                                  // mark visited
        for (int i = 0; i < 4; i++) {
            int nx = x + direction[i][0];
            int ny = y + direction[i][1];
            if (dfs(board, word, nx, ny, p + 1) == true)    // dive in
                return true;
        }
        board[x][y] = word[p];                              // mark restored, backtrack

        return false;
    }
};

int main() {
    Solution *s = new Solution();

    vector<vector<char> > v;
    char c1[] = {'A','B','C','E'}; vector<char> v1(c1, c1 + 4); v.push_back(v1);
    char c2[] = {'S','F','C','S'}; vector<char> v2(c2, c2 + 4); v.push_back(v2);
    char c3[] = {'A','D','E','E'}; vector<char> v3(c3, c3 + 4); v.push_back(v3);
    
    cout << s->exist(v, "ABCCED") << endl;
}