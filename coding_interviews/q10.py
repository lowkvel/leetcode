


"""
    斐波那契数列

    写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：
        F(0) = 0,   F(1) = 1
        F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
    斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

    答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

    示例 1：
        输入：n = 2
        输出：1

    示例 2：
        输入：n = 5
        输出：5
 
    提示：
        0 <= n <= 100

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

class Solution:

    # simple recursion, ms, mb, time o(n), space o(), 超出时间限制
    def fib(self, n: int) -> int:
        if n == 0:      # edge case 0: 0
            return 0
        if n == 1:      # edge case 1: 1
            return 1
        return self.fib(n - 1) + self.fib(n - 2)        # recursion

    # dynamic programming, iteration with list of size n, 44ms, 14.9mb, time o(n), space o(n)
    def fib2(self, n: int) -> int:
        ans = []
        ans.append(0)   # edge case 0: 0
        ans.append(1)   # edge case 1: 1
        for index in range(2, n+1, 1):                  # iteration
            ans.append(ans[index-1] + ans[index-2])
        return ans[n] % 1000000007                      # % 1000000007

    # dynamic programming, iteration with list of size 2, 48ms, 14.8mb, time o(n), space o(1)
    def fib3(self, n: int) -> int:
        a, b = 0, 1
        for index in range(n):
            a, b = b, (a + b) % 1000000007              # looping a and b, 求余运算规则： 设正整数 x,y,p ，求余符号为 % ，则有 (x+y)%p=(x%p+y%p)%p
        return a % 1000000007                           # % 1000000007

    # matrix, ms, mb, time o(logn), space o()
    def fib4(self, n: int) -> int:
        pass

if __name__ == '__main__':

    s = Solution()

    input = [
        2,
        5,
        37,
        45,
    ]

    print('-----')
    for item in input:
        #print(s.fib(item))
        print(s.fib2(item))
        print(s.fib3(item))
        print(s.fib4(item))
        print('-----')