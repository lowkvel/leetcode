
# same as lc50
"""
    数值的整数次方

    实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题。

    示例 1：
        输入：x = 2.00000, n = 10
        输出：1024.00000
        
    示例 2：
        输入：x = 2.10000, n = 3
        输出：9.26100

    示例 3：
        输入：x = 2.00000, n = -2
        输出：0.25000
        解释：2-2 = 1/22 = 1/4 = 0.25
 
    提示：
        -100.0 < x < 100.0
        -2^31 <= n <= 2^(31-1)
        -10^4 <= xn <= 10^4

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

class Solution:

    # simple solution, ms, mb, time o(n), space o(1)    # time limits exceeded
    def myPow(self, x: float, n: int) -> float:
        if n == 0:      # power of 0 gives 1
            return 1

        if x == 0:      # base of 0 gives 0
            return 0

        result = 1
        for index in range(0, abs(n), 1):
            result = result * x    

        if n < 0:       # negative power gives 1/x
            result = 1 / result

        return result

    # divide and conquer, recursion, bit operation, 48ms, 14.9mb, time o(log2 n), space o(log2 n)
    def myPow2(self, x: float, n: int) -> float:

        def recursion(x: float, n:int) -> float:
            if n == 0:      # edge case, x^0 = 1
                return 1    
            
            if n == 1:      # edge case, x^1 = x
                return x

            """
            # normal operation
            result = recursion(x, n // 2)
            result = result * result
            if n % 2 == 1:
                result = result * x
            """

            # bit operation
            result = recursion(x, n >> 1)   # n // 2 === n >> 1
            result = result * result
            if n & 0b1:                     # n % 2 === n & 0b1
                result = result * x

            return result

        if n == 0:      # power of 0 gives 1
            return 1

        if x == 0:      # base of 0 gives 0
            return 0

        result = recursion(x, abs(n))

        if n < 0:
            result = 1 / result

        return result

    # divide and conquer, loop, bit operation, 40ms, 14.9mb, time o(log2 n), space o(1)
    """
        思路二：迭代
            1. 首先处理n为负数的情况，把x取一下倒数并且把n变为正数即可
            2. 接下来以x = 2.0, n = 18为例解释一下迭代的过程   
                18 的二进制数为 0b10010（0b开头表示二进制数）
                    x^18 = x^16 ∗ x^2 = x^0b10000 ∗ x^0b10
                令循环体为【x ∗= x，n >>= 1】
                    循环1次的时候，【n = 18】为偶数，可以得到【x^2 = 4.0】
                    循环2次的时候，【n =  9】为奇数，把【x^2 = 4.0】乘到结果中，随后得到【x^4 = 16.0】
                    循环3次的时候，【n =  4】为偶数，可以得到【x^8 = 256.0】
                    循环4次的时候，【n =  2】为偶数，可以得到【x^16 = 65536.0】
                    循环5次的时候，【n =  1】为奇数，把【x^16 = 65536.0】乘到结果中，随后得到【x^32 = 4294967296.0】
                    循环结束
                也就是n的二进制数中有几个1就会乘几次，且乘数在循环中一次一次倍增

        作者：edelweisskoko
        链接：https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/solution/jian-zhi-offer-16-shu-zhi-de-zheng-shu-c-rgqy/
        来源：力扣（LeetCode）
        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    """
    def myPow3(self, x: float, n: int) -> float:
        if n == 0:      # power of 0 gives 1
            return 1

        if x == 0:      # base of 0 gives 0
            return 0

        result = 1
        if n < 0:               # x^-n = (1/x)^n, assume n > 0
            x, n = 1 / x, -n
        while n:
            if n & 1:
                result = result * x
            x = x * x
            n = n >> 1

        return result


if __name__ == '__main__':

    s = Solution()

    input = [
        #[2.0, 10],
        [2.0, 18],
        [2.1, 3],
        [2.0, -2],

        [-2.0, 2],
        [-2.0, 3],
        [-2.0, -2],
        [-2.0, -3],

        [0, 0],
        [0, 1],
        [0, -1],
        [1, 0],
        [-1, 0],

    ]

    print('-----')
    for item in input:
        print(s.myPow(item[0], item[1]))
        print(s.myPow2(item[0], item[1]))
        print(s.myPow3(item[0], item[1]))
        print('-----')