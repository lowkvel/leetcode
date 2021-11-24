/*
    977. 有序数组的平方

    给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

    示例 1：
        输入：nums = [-4,-1,0,3,10]
        输出：[0,1,9,16,100]
        解释：平方后，数组变为 [16,1,0,9,100]
        排序后，数组变为 [0,1,9,16,100]

    示例 2：
        输入：nums = [-7,-3,2,3,11]
        输出：[4,9,9,49,121]
    
    提示：
        1 <= nums.length <= 104
        -104 <= nums[i] <= 104
        nums 已按 非递减顺序 排序
     
    进阶：
        请你设计时间复杂度为 O(n) 的算法解决本问题

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/squares-of-a-sorted-array
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    // sort
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
            ans.push_back(nums[i] * nums[i]);
        sort(ans.begin(), ans.end());
        return ans;
    }

    // dual pointers
    vector<int> sortedSquares2(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans(nums.size());

        for (int head = 0, tail = len - 1, ansp = len - 1; head <= tail; ) {
            if (nums[head] * nums[head] > nums[tail] * nums[tail]) {
                ans[ansp] = nums[head] * nums[head];
                ++head;
            } else {
                ans[ansp] = nums[tail] * nums[tail];
                --tail;
            }
            --ansp;
        }

        return ans;
    }
};

int main() {
    Solution *s = new Solution();

}
