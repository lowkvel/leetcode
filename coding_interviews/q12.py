from typing import List

# same question as lc79
"""
    矩阵中的路径

    给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
    单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

    例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。
        ABCE
        SFCS
        ADEE

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

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

class Solution:

    # dfs, 200ms, 18.2mb, time o(mn*(4-1)^len(word)), space o(mn)
    def exist(self, board: List[List[str]], word: str) -> bool:

        def dfs(i: int, j:int, p: int) -> bool:

            # bound, out of range, not equal, terminate this branch search
            if not 0 <= i < len(board) or not 0 <= j < len(board[0]) or board[i][j] != word[p]:
                return False

            # solution found
            if p == len(word) - 1:
                return True

            # mark visited
            board[i][j] = '-'
            # dfs for up, down, left, right
            result = dfs(i - 1, j, p + 1) or dfs(i + 1, j, p + 1) or dfs(i, j - 1, p + 1) or dfs(i, j + 1, p + 1)
            # restore unvisited
            board[i][j] = word[p]
            return result

        for i in range(0, len(board), 1):
            for j in range(0, len(board[i]), 1):
                if dfs(i, j, 0) == True:
                    return True
        return False
        
        
                    
if __name__ == '__main__':

    s = Solution()

    input = [
        [[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], "ABCCED"],
        [[["a","b"],["c","d"]], "abcd"],
    ]

    print('-----')
    for item in input:
        print(s.exist(item[0], item[1]))

        print('-----')

