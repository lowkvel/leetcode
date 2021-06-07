from typing import List

"""
    打印从1到最大的n位数

    输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

    示例 1:
        输入: n = 1
        输出: [1,2,3,4,5,6,7,8,9]
     
    说明：
        用返回一个整数列表来代替打印
        n 为正整数

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

class Solution:

    # simple solution, 56ms, 20.3mb, time o(10^n), space o(1)
    def printNumbers(self, n: int) -> List[int]:

        # deal with invalid input
        if not isinstance(n, int) or n <= 0:
            return None
        
        # calculate the min (n+1)-digit number, 3 -> 1000
        import math
        min_np1 = int(math.pow(10, n))

        result = []
        for index in range (1, min_np1, 1):
            result.append(index)
        return result

    # python special, 40ms, 20.3mb, time o(10^n), space o(1)
    def printNumbers2(self, n: int) -> List[int]:

        # deal with invalid input
        if not isinstance(n, int) or n <= 0:
            return None

        return list(range(1, 10 ** n))





if __name__ == '__main__':

    s = Solution()

    input = [
        1,
        2,

        's',
        0,
        -1,
        0.1,
        1.1, 


    ]

    print('-----')
    for item in input:
        print(s.printNumbers(item))
        print(s.printNumbers2(item))
        print(s.printNumbers3(item))
        print(s.printNumbers4(item))

        print('-----')