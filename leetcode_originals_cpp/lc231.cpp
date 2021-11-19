/*
    231. 2的幂

    给你一个整数 n，请你判断该整数是否是 2 的幂次方。如果是，返回 true ；否则，返回 false 。
    如果存在一个整数 x 使得 n == 2x ，则认为 n 是 2 的幂次方。

    示例 1：
        输入：n = 1
        输出：true
        解释：20 = 1

    示例 2：
        输入：n = 16
        输出：true
        解释：24 = 16

    示例 3：
        输入：n = 3
        输出：false

    示例 4：
        输入：n = 4
        输出：true

    示例 5：
        输入：n = 5
        输出：false
    
    提示：
        -2^31 <= n <= 2^31 - 1
    
    进阶：你能够不使用循环/递归解决此问题吗？

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/power-of-two
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>

using namespace std;

class Solution {
public:
    // n & (n - 1)
    /*
        一个数 n 是 2 的幂，当且仅当 n 是正整数，并且 n 的二进制表示中仅包含 1 个 1（最高位的 1）。

            假设 n 的二进制表示为       (a10⋯0)_2，其中 a 表示若干个高位，1 表示最低位的那个 1，0⋯0 表示后面的若干个 0，
            那么 n − 1 的二进制表示为   (a01⋯1)_2 

            我们将 (a10⋯0)_2 与 (a01⋯1)_2 进行按位与运算，高位 a 不变，在这之后的所有位都会变为 0，这样我们就将最低位的那个 1 移除了。

        因此，如果 n 是正整数并且 n & (n - 1) = 0，那么 n 就是 2 的幂。

        作者：LeetCode-Solution
        链接：https://leetcode-cn.com/problems/power-of-two/solution/2de-mi-by-leetcode-solution-rny3/
        来源：力扣（LeetCode）
        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    */
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }

    // n & (-n)
    /*
        其中 -n 是 n 的相反数，是一个负数。该位运算技巧可以直接获取 n 二进制表示的最低位的 1。

        由于负数是按照补码规则在计算机中存储的，−n 的二进制表示为 n 的二进制表示的每一位取反再加上 1，因此它的原理如下：

            假设 n 的二进制表示为   (a10⋯0)_2，其中 a 表示若干个高位，1 表示最低位的那个 1，0⋯0 表示后面的若干个 0，
            那么 −n 的二进制表示为  (a'01⋯1)_2 + (1)_2 = (a'10⋯0)_2

            其中 a' 表示将 a 每一位取反。
            我们将 (a10⋯0)_2 与 (a'10⋯0)_2 进行按位与运算，高位全部变为 0，最低位的 1 以及之后的所有 0 不变，这样我们就获取了 n 二进制表示的最低位的 1。

        因此，如果 n 是正整数并且 n & (-n) = n，那么 n 就是 2 的幂。

        作者：LeetCode-Solution
        链接：https://leetcode-cn.com/problems/power-of-two/solution/2de-mi-by-leetcode-solution-rny3/
        来源：力扣（LeetCode）
        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    */
    bool isPowerOfTwo2(int n) {
        return n > 0 && (n & (-n)) == n;
    }

    // divisor
    /*
        在题目给定的 32 位有符号整数的范围内，最大的 2 的幂为 2^30 = 10737418242。
        我们只需要判断 n 是否是 2^30 的约数即可。

        作者：LeetCode-Solution
        链接：https://leetcode-cn.com/problems/power-of-two/solution/2de-mi-by-leetcode-solution-rny3/
        来源：力扣（LeetCode）
        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    */
    bool isPowerOfTwo3(int n) {
        return n > 0 && ((1 << 30) % n == 0);
    }
};

int main() {

}