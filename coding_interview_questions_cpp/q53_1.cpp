/*
    在排序数组中查找数字I

    统计一个数字在排序数组中出现的次数。

    示例 1:
        输入: nums = [5,7,7,8,8,10], target = 8
        输出: 2

    示例 2：
        输入: nums = [5,7,7,8,8,10], target = 6
        输出: 0
     

    提示：
        0 <= nums.length <= 105
        -109 <= nums[i] <= 109
        nums 是一个非递减数组
        -109 <= target <= 109

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == target)
                count++;
        return count;
    }

    // binary search
    int binarySearch(vector<int>& nums, int target, bool isLower) {
        int left = 0; 
        int right = nums.size() - 1;
        int ans = nums.size();          // initialize answer to nums size (all elements are target)

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if ((isLower == true && nums[mid] >= target) || // find index of the first element >= target
                nums[mid] > target) {                       // find index of the first element > target
                right = mid - 1;
                ans = mid;
            } else
                left = mid + 1;
        }

        return ans;
    }

    int search2(vector<int> &nums, int target) {
        int left = binarySearch(nums, target, true);        // find index of the first element >= target
        int right = binarySearch(nums, target, false) - 1;  // find index of the first element > target, then -1
        if (left <= right && right < nums.size() && 
            nums[left] == target && nums[right] == target)
            return right - left + 1;
        return 0;
    }
};

int main() {

}