/*
    7. 整数反转

    给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
    如果反转后整数超过 32 位的有符号整数的范围 [−2^31,  2^31 − 1] ，就返回 0。
    假设环境不允许存储 64 位整数（有符号或无符号）。
    
    示例 1：
        输入：x = 123
        输出：321

    示例 2：
        输入：x = -123
        输出：-321

    示例 3：
        输入：x = 120
        输出：21

    示例 4：
        输入：x = 0
        输出：0
     
    提示：
        -2^31 <= x <= 2^31 - 1

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/reverse-integer
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            // https://leetcode-cn.com/problems/reverse-integer/solution/zheng-shu-fan-zhuan-by-leetcode-solution-bccn/ 
            if (ans < INT_MIN / 10 || ans > INT_MAX / 10)
                return 0;

            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
};

int main() {
    Solution *s = new Solution();

    cout << s->reverse(-123) << endl;
}