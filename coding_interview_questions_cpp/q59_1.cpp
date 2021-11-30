/*
    59-1. 滑动窗口的最大值

    给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

    示例:
        输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
        输出: [3,3,5,5,6,7] 
        解释: 

        滑动窗口的位置                  最大值
        ---------------               -----
        [1  3  -1] -3  5  3  6  7       3
         1 [3  -1  -3] 5  3  6  7       3
         1  3 [-1  -3  5] 3  6  7       5
         1  3  -1 [-3  5  3] 6  7       5
         1  3  -1  -3 [5  3  6] 7       6
         1  3  -1  -3  5 [3  6  7]      7

    提示：
        你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。

    注意：本题与主站 239 题相同：https://leetcode-cn.com/problems/sliding-window-maximum/

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>
# include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0 || k == 0)
            return {};

        vector<int> ans;
        deque<int> dq;
        
        // build window
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && dq.back() < nums[i])  // pop all elements smaller than current one from back
                dq.pop_back();
            dq.push_back(nums[i]);                      // push current element into dq, order maintained
        }
        ans.push_back(dq.front());                      // push current front of dq into ans

        // after window is built
        for (int i = k; i < nums.size(); i++) {
            if (dq.front() == nums[i - k])              // if current max (dq.front) is nums[i-k] (the element to be removed in this round), pop it because it wont be here after this round
                dq.pop_front();
            while (!dq.empty() && dq.back() < nums[i])  // pop all elements smaller than current one from back
                dq.pop_back();
            dq.push_back(nums[i]);                      // push current element into dq, order maintained
            ans.push_back(dq.front());                  // push current front of dq into ans
        }

        return ans;
    }
};

int main() {

}