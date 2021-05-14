
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

    # simple solution, ms, mb, time o(n), space o(1)    # out of time
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

    


if __name__ == '__main__':

    s = Solution()

    input = [
        #[2.0, 10],
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

        print('-----')