# same question as lc70
"""
    青蛙跳台阶

    一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

    答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

    示例 1：
        输入：n = 2
        输出：2

    示例 2：
        输入：n = 7
        输出：21

    示例 3：
        输入：n = 0
        输出：1

    提示：
        0 <= n <= 100

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

class Solution:

    # simple recursion, ms, mb, time o(n), space o(), 超出时间限制
    def numWays(self, n: int) -> int:
        if n == 0:      # edge case 0: 0
            return 1
        if n == 1:      # edge case 1: 1
            return 1
        return self.fib(n - 1) + self.fib(n - 2)        # recursion

    # dynamic programming, iteration with list of size n, 44ms, 14.9mb, time o(n), space o(n)
    def numWays2(self, n: int) -> int:
        ans = []
        ans.append(1)   # edge case 0: 0
        ans.append(1)   # edge case 1: 1
        for index in range(2, n+1, 1):                  # iteration
            ans.append(ans[index-1] + ans[index-2])
        return ans[n] % 1000000007                      # % 1000000007

    # dynamic programming, iteration with list of size 2, 36ms, 14.6mb, time o(n), space o(1)
    def numWays3(self, n: int) -> int:
        a, b = 1, 1
        for index in range(n):
            a, b = b, (a + b) % 1000000007              # looping a and b, 求余运算规则： 设正整数 x,y,p ，求余符号为 % ，则有 (x+y)%p=(x%p+y%p)%p
        return a % 1000000007                           # % 1000000007

    # matrix, ms, mb, time o(logn), space o()
    def numWays4(self, n: int) -> int:
        pass

if __name__ == '__main__':

    s = Solution()

    input = [
        0,
        1,
        2,
        5,
        7,
        37,
        45,
    ]

    print('-----')
    for item in input:
        #print(s.numWays(item))
        print(s.numWays2(item))
        print(s.numWays3(item))
        print(s.numWays4(item))
        print('-----')