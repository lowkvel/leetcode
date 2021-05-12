
# same as lc343
"""
    剪绳子 II

    给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m - 1] 。
    请问 k[0]*k[1]*...*k[m - 1] 可能的最大乘积是多少？
        例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

    答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

    示例 1：
        输入: 2
        输出: 1
        解释: 2 = 1 + 1, 1 × 1 = 1

    示例 2:
        输入: 10
        输出: 36
        解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36
 
    提示：
        2 <= n <= 1000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

class Solution:

    # 求 (x^a) % p —— 循环求余法
    def remainder(x, a, p):
        rem = 1
        for _ in range(a):
            rem = (rem * x) % p
        return rem

    # 求 (x^a) % p —— 快速幂求余
    def remainder(x, a, p):
        rem = 1
        while a > 0:
            if a % 2: rem = (rem * x) % p
            x = x ** 2 % p
            a //= 2
        return rem

    """
        作者：jyd
        链接：https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof/solution/mian-shi-ti-14-ii-jian-sheng-zi-iitan-xin-er-fen-f/
        来源：力扣（LeetCode）
        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    """

    # greedy algorithm, 48ms, 14.9mb, time o(log a), space o(1)
    def cuttingRope(self, n: int) -> int:
        # has to cut under these senarios
        if n <= 1:      # 0, 1:     0 * (0, 1) = 0
            return 0
        elif n == 2:    # 2:        1 * 1 = 1
            return 1
        elif n == 3:    # 3:        1 * 2 = 2
            return 2
        
        a, b, p = n // 3, n % 3, 1000000007

        if b == 0: 
            return 3 ** a % p
        elif b == 1: 
            return 3 ** (a - 1) * 4 % p
        else:
            return 3 ** a * 2 % p






if __name__ == '__main__':

    s = Solution()

    input = [
        2,
        10,

        0,
        -1,
    ]

    print('-----')
    for item in input:
        print(s.cuttingRope(item))

        print('-----')