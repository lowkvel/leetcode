/*
    49. 丑数

    我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。

    示例:
        输入: n = 10
        输出: 12
        解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。

    说明:  
        1 是丑数。
        n 不超过1690。

    注意：本题与主站 264 题相同：https://leetcode-cn.com/problems/ugly-number-ii/

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/chou-shu-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        int a = 0;  // for 2
        int b = 0;  // for 3
        int c = 0;  // for 5
        vector<int> dp;
        dp.push_back(1);

        for (int i = 1; i < n; i++) {
            int next2 = dp[a] * 2;
            int next3 = dp[b] * 3;
            int next5 = dp[c] * 5;
            dp.push_back(min(min(next2, next3), next5));
            if (dp.back() == next2) a++;
            if (dp.back() == next3) b++;
            if (dp.back() == next5) c++;
        }

        return dp[n - 1];
    }
};

int main() {

}