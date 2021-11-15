/*
    46. 把数字翻译成字符串

    给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

    示例 1:
        输入: 12258
        输出: 5
        解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
    
    提示：
        0 <= num < 231

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>

using namespace std;

class Solution {
public:
    /*
    字符串的第 i 位置，用 f(i) 表示以第 i 位结尾的前缀串翻译的方案数，
    考虑第 i 位单独翻译 和 与前一位连接起来再翻译对 f(i) 的贡献。
        可以单独作为一位来翻译                                                  f(i) = f(i − 1)，继承前一位的总数
        如果第 i - 1 位和第 i 位组成的数字在 10 到 25 之间，可以把这两位连起来翻译    f(i) = f(i − 2)，继承再前一位的总数
        ->  f(i) = f(i − 1) + f(i − 2)[i − 1 ≥ 0, 10 ≤ x ≤ 25]
            f(-1) = 0, f(0) = 1

    作者：LeetCode-Solution
    链接：https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/solution/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-by-leetcode-sol/
    来源：力扣（LeetCode）
    著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    */
    int translateNum(int num) {
        string snum = to_string(num);
        // initiazation
        int p = 0;  // f(i - 2)
        int q = 0;  // f(i - 1)
        int r = 1;  // f(i)

        for (int i = 0; i < snum.size(); ++i) {
            // rolling index forward
            p = q;
            q = r;
            // initialized to 0 at position i, will be f(i − 1) + f(i − 2)[i − 1 ≥ 0, 10 ≤ x ≤ 25] calculation afterwards
            r = 0;

            // f(i) = f(i - 1)
            r = r + q;

            // f(i) = f(i - 2)
            if (i == 0)
                continue;
            else if (snum.substr(i - 1, 2) >= "10" && snum.substr(i - 1, 2) <= "25")
                r = r + p;
        }
        return r;
    }
};

int main() {

}