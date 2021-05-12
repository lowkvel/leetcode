from typing import List

# same question as lc240
"""
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
"""

class Solution:

    # brute force, 52ms, 18.7mb, time o(nm), space o(1)
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:

        # check for invalid input
        if matrix is None or len(matrix) == 0:
            return False

        # brute force search
        for i in range(0, len(matrix), 1):
            for j in range(0, len(matrix[0]), 1):
                if matrix[i][j] == target:
                    return True
        return False

    # search from up right corner, 48ms, 18.5mb, time o(n+m), space o(1)
    def findNumberIn2DArray2(self, matrix: List[List[int]], target: int) -> bool:
        
        # check for invalid input
        if matrix is None or len(matrix) == 0:
            return False

        # search from up right-corner (or bottom-left corner)
        up_right_x = len(matrix[0]) - 1
        up_right_y = 0

        while up_right_x >= 0 and up_right_y <= len(matrix) - 1:
            if target == matrix[up_right_y][up_right_x]:
                return True
            elif target < matrix[up_right_y][up_right_x]:
                up_right_x = up_right_x - 1
            else:
                up_right_y = up_right_y + 1
        return False



if __name__ == "__main__":
    
    s = Solution()

    input = [
        [[[1,   4,  7, 11, 15],
          [2,   5,  8, 12, 19],
          [3,   6,  9, 16, 22],
          [10, 13, 14, 17, 24],
          [18, 21, 23, 26, 30]], 5],    # exists
        [[[1,   4,  7, 11, 15],
          [2,   5,  8, 12, 19],
          [3,   6,  9, 16, 22],
          [10, 13, 14, 17, 24],
          [18, 21, 23, 26, 30]], 20],   # not exists
        [[[1,   4,  7, 11, 15],
          [2,   5,  8, 12, 19],
          [3,   6,  9, 16, 22],
          [10, 13, 14, 17, 24],
          [18, 21, 23, 26, 30]], -1],   # less than minimum
        [[[1,   4,  7, 11, 15],
          [2,   5,  8, 12, 19],
          [3,   6,  9, 16, 22],
          [10, 13, 14, 17, 24],
          [18, 21, 23, 26, 30]], 100],  # greater than maximum
          
        [[[-5]], -5],                   # single element
        [[], 0],                        # empty
        [None, 0],                      # None
    ]

    print('-----')
    for item in input:
        print(s.findNumberIn2DArray(item[0], item[1]))      # brute force search
        print(s.findNumberIn2DArray2(item[0], item[1]))     # search from up-right/bottom-left corner
        print('-----')