/*
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
*/

# include <iostream>
# include <vector>

using namespace std;

/*
    循环求余法证明: 大数越界： 随着 n 增大, f(n) 会超过 Int32 甚至 Int64 的取值范围，导致最终的返回值错误。

    求余运算规则:   设正整数 x, y, p ，求余符号为 % ，则有 (x + y) % p = (x % p + y % p) % p 。
    解析：         根据以上规则，可推出 f(n) % p = [f(n − 1) % p + f(n − 2) % p] % p ，
                  从而可以在循环过程中每次计算 sum = (a + b) % 1000000007 ，此操作与最终返回前取余等价。

    作者：jyd
    链接：https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/solution/mian-shi-ti-10-i-fei-bo-na-qi-shu-lie-dong-tai-gui/
    来源：力扣（LeetCode）
    著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
    // recursion
    int fib(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        return (fib(n - 1) + fib(n - 2)) % 1000000007;
    }

    // dynamic programming with auxilary vector
    int fib2(int n) {
        vector<int> ans;
        ans.push_back(0);
        ans.push_back(1);
        for (int i = 2; i <= n; i++)
            ans.push_back((ans[i - 1] + ans[i - 2]) % 1000000007);
        return ans[n] % 1000000007;
    }

    // dynamic programming with three variables
    int fib3(int n) {
        int v1 = 0;
        int v2 = 1;
        int sum = -1;
        for (int i = 2; i <= n + 1; i++) {      // one more step, because v1 is returned
            sum = (v1 + v2) % 1000000007;
            v1 = v2;
            v2 = sum;
        }
        return v1 % 1000000007;
    }

    // matric
    int fib4(int n) {

        return -1;
    }
};

int main() {
    Solution *s = new Solution();

    printf("%d\n", s->fib2(0));
    printf("%d\n", s->fib2(1));
    printf("%d\n", s->fib2(2));
    printf("%d\n", s->fib2(5));
    printf("%d\n", s->fib2(9));
}