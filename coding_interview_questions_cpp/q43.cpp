/*
    43. 1-n整数中1出现的次数

    输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。
    例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。

    示例 1：
        输入：n = 12
        输出：5

    示例 2：
        输入：n = 13
        输出：6
    
    限制：
        1 <= n < 2^31
    
    注意：本题与主站 233 题相同：https://leetcode-cn.com/problems/number-of-digit-one/

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        long long mulk = 1;
        int ans = 0;
        for (int k = 0; n >= mulk; ++k) {
            ans += (n / (mulk * 10)) * mulk + min(max(n % (mulk * 10) - mulk + 1, 0LL), mulk);
            mulk *= 10;
        }
        return ans;
    }
};

int main() {

}