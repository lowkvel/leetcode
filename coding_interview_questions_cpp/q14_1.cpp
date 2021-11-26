/*
    14-1. 剪绳子

    给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。
    请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？
    例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

    示例 1：
        输入: 2
        输出: 1
        解释: 2 = 1 + 1, 1 × 1 = 1

    示例 2:
        输入: 10
        输出: 36
        解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36

    提示：
        2 <= n <= 58

    注意：本题与主站 343 题相同：https://leetcode-cn.com/problems/integer-break/

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/jian-sheng-zi-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    // greedy, 3n+2
    int cuttingRope(int n) {
        if (n == 0)
            return 0;
        if (n <= 2)
            return 1;
        if (n == 3)
            return 2;

        int ans = 1;
        while (n > 4) {
            n = n - 3;
            ans = ans * 3;
        }
        ans = ans * n;

        return ans;
    }

    // dynamic programming
    int cuttingRope2(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for (int i = 3; i <= n; i++) 
            for (int j = 2; j < i; j++)                         // cut the rope with length j: [2, i)
                dp[i] = max(dp[i],                              // for different j, choose a better j to get max dp[i]
                            max(j * (i - j), j * dp[i - j]));   // after the length j is cut, choose to quit or continue cutting
        
        return dp[n];
    }
};

int main() {

}