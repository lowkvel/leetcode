/*
    53. 最大子序和

    给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

    示例 1：
        输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
        输出：6
        解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
    
    示例 2：
        输入：nums = [1]
        输出：1
    
    示例 3：
        输入：nums = [0]
        输出：0
    
    示例 4：
        输入：nums = [-1]
        输出：-1
    
    示例 5：
        输入：nums = [-100000]
        输出：-100000

    提示：
        1 <= nums.length <= 105
        -104 <= nums[i] <= 104
     
    进阶：
        如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/maximum-subarray
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    /*
        动态规划

        假设 nums 数组的长度是 n，下标从 0 到 n−1。

        我们用 f(i) 代表以第 i 个数结尾的「连续子数组的最大和」，那么很显然我们要求的答案就是：

                max     {f(i)}
            0 ≤ i ≤ n−1

        因此我们只需要求出每个位置的 f(i)，然后返回 f 数组中的最大值即可。

        那么我们如何求 f(i) 呢？
        我们可以考虑 nums[i] 单独成为一段还是加入 f(i−1) 对应的那一段，
        这取决于 nums[i] 和 f(i−1) + nums[i] 的大小，我们希望获得一个比较大的.

        于是可以写出这样的动态规划转移方程：

            f(i) = max{f(i−1) + nums[i], nums[i]}

        不难给出一个时间复杂度 O(n)、空间复杂度 O(n) 的实现，即用一个 f 数组来保存 f(i) 的值，用一个循环求出所有 f(i)。
        考虑到 f(i) 只和 f(i−1) 相关，于是我们可以只用一个变量 preans 来维护对于当前 f(i) 的 f(i−1) 的值是多少，从而让空间复杂度降低到 O(1)，这有点类似「滚动数组」的思想。

        作者：LeetCode-Solution
        链接：https://leetcode-cn.com/problems/maximum-subarray/solution/zui-da-zi-xu-he-by-leetcode-solution/
        来源：力扣（LeetCode）
        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    */
    int maxSubArray(vector<int>& nums) {
        int preans  = 0;
        int maxans = nums[0];
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            preans  + (*it) >= (*it) ? preans  = preans  + (*it) : preans  = (*it);
            maxans > preans  ? maxans = maxans : maxans = preans;
        }
        return maxans;
    }
};

int main() {
    Solution *s = new Solution();

    int a1[] = {-2,1,-3,4,-1,2,1,-5,4}; 
    vector<int> v1(a1, a1 + 9);
    printf("%d\n", s->maxSubArray(v1));
}