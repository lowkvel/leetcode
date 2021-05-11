from typing import List
from queue import Queue

"""
    机器人的运动范围

    地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
    一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。
        例如：当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。
    请问该机器人能够到达多少个格子？

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
"""

class Solution:

    # bfs, 136ms, 15.3mb, time o(mn), space o(mn)
    def movingCount(self, m: int, n: int, k: int) -> int:
        def digitSum(number: int) -> int:
            sum = 0
            while number > 0:
                sum = sum + number % 10
                number = number // 10
            return sum

        q = Queue()     # used for bfs
        s = set()       # used for counting, set feature: elements are all unique
        
        q.put((0, 0))
        while not q.empty() == True:
            # get first element pair from queue
            x, y = q.get()
            # if the pair from queue not in set (not visited), and the index is valid for both x and y, and the digit sum <= k
            if (x, y) not in s and 0 <= x < m and 0 <= y < n and (digitSum(x) + digitSum(y) <= k):
                s.add((x, y))
                q.put((x + 1, y))   # right
                q.put((x, y + 1))   # down
        return len(s)

    # iteration, 52ms, 15mb, time o(mn), space o(mn)
    def movingCount2(self, m: int, n: int, k: int) -> int:
        def digitSum(number: int) -> int:
            sum = 0
            while number > 0:
                sum = sum + number % 10
                number = number // 10
            return sum

        s = set()
        s.add((0, 0))
        for i in range(0, m, 1):
            for j in range(0, n, 1):
                # if any of two predecessors (from left or above) is in the set (which should be checked before and valid)
                # and current (i, j) is valid, add it to the set
                if ((i - 1, j) in s or (i, j - 1) in s) and (digitSum(i) + digitSum(j) <= k):
                    s.add((i, j))
        return len(s)



if __name__ == '__main__':

    s = Solution()

    input = [
        [2,3,1],
        [3,1,0],

    ]

    print('-----')
    for item in input:
        print(s.movingCount(item[0], item[1], item[2]))
        print(s.movingCount2(item[0], item[1], item[2]))

        print('-----')
