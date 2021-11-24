/*
    283. 移动零

    给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

    示例:
        输入: [0,1,0,3,12]
        输出: [1,3,12,0,0]

    说明:
        必须在原数组上操作，不能拷贝额外的数组。
        尽量减少操作次数。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/move-zeroes
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    // dual pointers
    void moveZeroes(vector<int>& nums) {
        int left = 0;           // all values on the left of the left pointer are non-zeroes
        int right = 0;          // all values between left and right pointers are zeroes
        int len = nums.size();

        while (right < len) {
            if (nums[right] != 0) {             // right meets a non-zero value
                swap(nums[left], nums[right]);  // swap left (zero) and right (non-zero)
                left++;                         // move left to next zero
            }
            right++;                            // move right to find next non-zero value
        }
    }

    // zero filler
    void moveZeroes2(vector<int>& nums) {
        int position = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != 0)
                nums[position++] = nums[i];
        for (int i = position; i < nums.size(); i++)
            nums[i] = 0;
    }
};

int main() {
    Solution *s = new Solution();

}
