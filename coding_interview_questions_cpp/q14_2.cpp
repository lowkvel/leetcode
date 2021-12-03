/*
    14-2. 剪绳子

    给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m - 1] 。
    请问 k[0]*k[1]*...*k[m - 1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

    答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

    示例 1：
        输入: 2
        输出: 1
        解释: 2 = 1 + 1, 1 × 1 = 1

    示例 2:
        输入: 10
        输出: 36
        解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36
    
    提示：
        2 <= n <= 1000
    
    注意：本题与主站 343 题相同：https://leetcode-cn.com/problems/integer-break/

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    // greedy
    int cuttingRope(int n) {
        if (n == 0)
            return 0;
        if (n <= 2)
            return 1;
        if (n == 3)
            return 2;

        int ans = 1;
        int temp = 0;
        while (n > 4) {
            n = n - 3;
            temp = ans;
            for (int i = 0; i < 3 - 1; i++)
                ans = (ans + temp) % 1000000007;
        }

        temp = ans;
        for (int i = 0; i < n - 1; i++)
            ans = (ans + temp) % 1000000007;

        return ans;
    }

    // dynamic programming
    int cuttingRope(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
            for (int j = 2; j < i; j++)                         // cut the rope with length j: [2, i)
                dp[i] = max(dp[i],                              // for different j, choose a better j to get max dp[i]
                            max(j * (i - j), j * dp[i - j]));   // after the length j is cut, choose to quit or continue cutting
            
        return dp[n];
    }
};

int main() {

}