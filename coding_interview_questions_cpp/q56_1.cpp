/*
    56-1. 数组中数字出现的次数

    一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
    请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

    示例 1：
        输入：nums = [4,1,4,6]
        输出：[1,6] 或 [6,1]

    示例 2：
        输入：nums = [1,2,10,4,1,4,3,3]
        输出：[2,10] 或 [10,2]
    
    限制：
        2 <= nums.length <= 10000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    /*
        思路

        先来考虑一个比较简单的问题：如果除了一个数字以外，其他数字都出现了两次，那么如何找到出现一次的数字？
        答案很简单：  全员进行异或操作即可。
                    考虑异或操作的性质：对于两个操作数的每一位，相同结果为 0，不同结果为 1。
                    那么在计算过程中，成对出现的数字的所有位会两两抵消为 0，最终得到的结果就是那个出现了一次的数字。

        那么这一方法如何扩展到找出两个出现一次的数字呢？
            如果我们可以把所有数字分成两组，使得：
                1.  两个只出现一次的数字在不同的组中；
                2.  相同的数字会被分到相同的组中。
            那么对两个组分别进行异或操作，即可得到答案的两个数字。这是解决这个问题的关键。

        那么如何实现这样的分组呢？
            记这两个只出现了一次的数字为 a 和 b，那么所有数字异或的结果就等于 a 和 b 异或的结果，我们记为 x。
            如果我们把 x 写成二进制的形式 x_k x_k-1 ... x_2 x_1 x_0，其中 x_i ∈ {0,1}
            我们考虑一下 x_i = 0 和 x_i = 1 的含义是什么？
                它意味着如果我们把 a 和 b 写成二进制的形式，
                a_i 和 b_i 的关系：x_i = 1 表示 a_i 和 b_i 不等，x_i = 0 表示 a_i 和 b_i 相等。
            
        假如我们任选一个不为 0 的 x_i ，按照第 i 位给原来的序列分组，如果该位为 0 就分到第一组，否则就分到第二组，这样就能满足以上两个条件，为什么呢？
            1.  这个方法在 x_i = 1 的时候 a 和 b 不被分在同一组，因为 x_i = 1 表示 a_i 和 b_i 不等，
                根据这个方法的定义「如果该位为 0 就分到第一组，否则就分到第二组」可以知道它们被分进了两组，所以满足了条件 1。
            2.  其次，两个相同的数字的对应位都是相同的，所以一个被分到了某一组，另一个必然被分到同一组，所以满足了条件 2。

        在实际操作的过程中，我们拿到序列的异或和 x 之后，对于这个「位」是可以任取的，只要它满足 x_i = 1 。
        但是为了方便，这里的代码选取的是「不为 0 的最低位」，当然你也可以选择其他不为 0 的位置。
        至此，答案已经呼之欲出了。

        算法
            先对所有数字进行一次异或，得到两个出现一次的数字的异或值。
            在异或结果中找到任意为 1 的位。
            根据这一位对所有的数字进行分组。
            在每个组内进行异或操作，得到两个数字。

        作者：LeetCode-Solution
        链接：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/solution/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-by-leetcode/
        来源：力扣（LeetCode）
        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    */
    vector<int> singleNumbers(vector<int>& nums) {
        int ans = 0;
        for (int n: nums)           // get x = a ^ b
            ans = ans ^ n;
        
        int div = 1;
        while ((div & ans) == 0)    // get first x where x_i = 1
            div = div << 1;

        int a = 0;                  // group 1
        int b = 0;                  // group 2
        for (int n: nums)
            if ((div & n) != 0)     // group 1 ^ to get a
                a = a ^ n;
            else                    // group 2 ^ to get b
                b = b ^ n;
        
        return vector<int>{a, b};
    }
};

int main() {

}
