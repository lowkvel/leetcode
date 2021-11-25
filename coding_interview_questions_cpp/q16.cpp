/*
    16. 数值的整数次方

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
        -2^31 <= n <= 2^31-1
        -10^4 <= x^n <= 10^4
     
    注意：本题与主站 50 题相同：https://leetcode-cn.com/problems/powx-n/

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>

using namespace std;

class Solution {
public:
    // loop
    double myPow(double x, int n) {
        if (n == 0)
            return 1.0;

        double ans = 1.0;
        for (int i = 0; i < abs(n); i++)
            ans = ans * x;
        return n > 0 ? ans : 1 / ans;
    }

    // division
    double myPow2(double x, int n) {
        if (n == 0)
            return 1;
        else if (n < 0)
            return myPow2(1/x, -(n + 1)) * 1/x;
        else if (n % 2 == 0)
            return myPow2(x * x, n / 2);
        else if (n % 2 == 1)
            return myPow2(x * x, n / 2) * x;

        return 0;
    }

    // quick pow
    double myPow3(double x, int n) {

    }
};

int main() {

}