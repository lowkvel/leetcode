/*
    21. 调整数组肾虚使奇数位于偶数前面

    输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。

    示例：
        输入：nums = [1,2,3,4]
        输出：[1,3,2,4] 
        注：[3,1,2,4] 也是正确的答案之一。

    提示：
        0 <= nums.length <= 50000
        0 <= nums[i] <= 10000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    // dual pointers, left & right
    vector<int> exchange(vector<int>& nums) {
        int left = 0; 
        int right = nums.size() - 1;

        while (left < right) {
            while (left < right && nums[left] % 2 == 1) 
                left++;
            while (left < right && nums[right] % 2 == 0)
                right--;

            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp; 
        }

        return nums;
    }

    // dual pointers, slow & fast
    vector<int> exchange2(vector<int>& nums) {
        int slow = 0;   // position of next odd number to place in
        int fast = 0;   // find next odd number to place on position slow

        while (fast < nums.size()) {
            if (nums[fast] % 2 == 1) {      // next odd number found, swap
                int temp = nums[slow];
                nums[slow] = nums[fast];
                nums[fast] = temp;

                slow++;
            }
            fast++;
        }

        return nums;
    }
};

int main() {

}