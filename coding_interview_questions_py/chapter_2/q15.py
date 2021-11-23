
# same as lc191
"""
    二进制中1的个数

    请实现一个函数，输入一个整数（以二进制串形式），输出该数二进制表示中 1 的个数。例如，把 9 表示成二进制是 1001，有 2 位是 1。因此，如果输入 9，则该函数输出 2。

    示例 1：
        输入：00000000000000000000000000001011
        输出：3
        解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。

    示例 2：
        输入：00000000000000000000000010000000
        输出：1
        解释：输入的二进制串 00000000000000000000000010000000 中，共有一位为 '1'。
    
    示例 3：
        输入：11111111111111111111111111111101
        输出：31
        解释：输入的二进制串 11111111111111111111111111111101 中，共有 31 位为 '1'。
    
    提示：
        输入必须是长度为 32 的 二进制串 。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    similar questions:
    1.  decide if a int n is power of 2.
        1>  if n is power of 2, then its binary representation will only contain the left-most 1, while (n-1) will have the left-most 0 and all other bits to be 1s
        2>  so if n & (n-1) == 0 then it is power of two
    2.  given two int m and n, decide how many steps are needed in order to turn m into n under binary representation.
        1>  calculate m xor n
        2>  count how many 1s exist in (m xor n) using n & (n-1) method
"""

class Solution:

    # right shift bit-wise, 44ms, 18.4mb, time o(log2 n), space o(1)
    def hammingWeight(self, n: int) -> int:
        count = 0
        while n != 0:
            if n & 1 == 1:          # right most bit is 1
                count = count + 1
            n = n >> 1              # right shift 1 bit 
        return count

    # n&(n-1), 48ms, 14.8mb, time o(n), space o(1)
    """
        let n = 1100, then n-1 = 1011, the right-most 1 changed to 0 and all 0s after it changed to 1s
        n & (n-1) = 1100 & 1011 = 1000, the right-most 1 changed to 0 compared to n it self
        so we only need to do n & (n-1) multiple times until all 1s changed to 0s
    """
    def hammingWeight2(self, n: int) -> int:
        count = 0
        while n != 0:
            count = count + 1
            n = n & (n - 1)
        return count


if __name__ == '__main__':

    s = Solution()

    input = [
        0b00000000000000000000000000001011,
        0b00000000000000000000000010000000,
        0b11111111111111111111111111111101,

    ]

    print('-----')
    for item in input:
        print(s.hammingWeight(item))
        print(s.hammingWeight2(item))
        print('-----')