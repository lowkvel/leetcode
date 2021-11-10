/*
    股票的最大利润

    假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？

    示例 1:
        输入: [7,1,5,3,6,4]
        输出: 5
        解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
            注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
    
    示例 2:
        输入: [7,6,4,3,1]
        输出: 0
        解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
     

    限制：
        0 <= 数组长度 <= 10^5

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    /**
     * @brief dynamic programming
     * 
     * @param prices 
     * @return int 
     * 
     * state definition:    设动态规划列表 dp ，dp[i] 代表以 prices[i] 为结尾的子数组的最大利润（简称为 前 i 日的最大利润）
     * initial state:       dp[0] = 0 ，即首日利润为 0 
     * state transfer:      前 i 日最大利润 dp[i] 等于前 i − 1 日最大利润 dp[i − 1] 和第 i 日卖出的最大利润中的最大值。
     *                      即:     dp[i] = max(dp[i − 1], prices[i] − min(prices[0:i]))
     *                      ->      dp[i] = max(dp[i − 1], prices[i] − min(min_price_so_far, prices[i])
     *                      ->      max_profit_so_far = max(max_profit_so_far, prices[i] − min(min_price_so_far, prices[i])
     */
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 1)      // exceptions
            return 0;

        int minPrice = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;
    }
};

int main() {
    Solution *s = new Solution();

    int a0[] = {};              vector<int> v0(a0, a0 + 0);
    int a1[] = {1};             vector<int> v1(a1, a1 + 1);
    int a2[] = {7,1,5,3,6,4};   vector<int> v2(a2, a2 + 6);
    int a3[] = {7,6,4,3,1};     vector<int> v3(a3, a3 + 5);

    printf("%d\n", s->maxProfit(v0));
    printf("%d\n", s->maxProfit(v1));
    printf("%d\n", s->maxProfit(v2));
    printf("%d\n", s->maxProfit(v3));
}