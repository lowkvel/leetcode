/*
    青蛙跳台阶

    一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

    答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

    示例 1：
        输入：n = 2
        输出：2

    示例 2：
        输入：n = 7
        输出：21

    示例 3：
        输入：n = 0
        输出：1

    提示：
        0 <= n <= 100

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    // recursion
    int numWays(int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 1;
        return (numWays(n - 1) + numWays(n - 2)) % 1000000007;
    }

    // dynamic programming with auxilary vector
    int numWays2(int n) {
        vector<int> ans;
        ans.push_back(1);
        ans.push_back(1);
        for (int i = 2; i <= n; i++)
            ans.push_back((ans[i - 1] + ans[i - 2]) % 1000000007);
        return ans[n] % 1000000007;
    }

    // dynamic programming with 3 variables
    int numWays3(int n) {
        int v1 = 1;
        int v2 = 1;
        int sum = -1;
        for (int i = 2; i <= n + 1; i++) {
            sum = (v1 + v2) % 1000000007;
            v1 = v2;
            v2 = sum;
        }
        return v1 % 1000000007;
    }
};

int main() {
    Solution *s = new Solution();

    printf("%d\n", s->numWays2(0));
    printf("%d\n", s->numWays2(1));
    printf("%d\n", s->numWays2(2));
    printf("%d\n", s->numWays2(7));
    printf("%d\n", s->numWays2(9));
}