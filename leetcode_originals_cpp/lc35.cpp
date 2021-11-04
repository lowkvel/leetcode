/*
    35. 搜索插入位置

    给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
    如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
    请必须使用时间复杂度为 O(log n) 的算法。

    示例 1:
        输入: nums = [1,3,5,6], target = 5
        输出: 2
    
    示例 2:
        输入: nums = [1,3,5,6], target = 2
        输出: 1
    
    示例 3:
        输入: nums = [1,3,5,6], target = 7
        输出: 4
    
    示例 4:
        输入: nums = [1,3,5,6], target = 0
        输出: 0
    
    示例 5:
        输入: nums = [1], target = 0
        输出: 0
     
    提示:
        1 <= nums.length <= 104
        -104 <= nums[i] <= 104
        nums 为无重复元素的升序排列数组
        -104 <= target <= 104

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/search-insert-position
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        /*
            查找二分，所求位置为目标的下标
            插入二分，所求位置为第一个大于等于目标的下标, left will be the anchor
        */

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // found, in this case, left must be adjacent to right
            // mid then will be placed at left's location
            // after that, right moves to mid - 1, 
            // loop ends
            if (nums[mid] == target) 
                right = mid - 1;
            else if (nums[mid] > target)    // in this case, simply moves right to mid - 1
                right = mid - 1;
            else if (nums[mid] < target)    // in this case, simply moves left to mid + 1
                left = mid + 1;             // then left keeps move towards right side, until left > right
        }

        return left;                        // anchor returns
    }
};

int main() {
    Solution *s = new Solution();

    int a1[] = {1,3,5,6}; 
    vector<int> v1(a1, a1 + 4);
    printf("%d\n", s->searchInsert(v1, 5));

    int a2[] = {1,3,5,6}; 
    vector<int> v2(a2, a2 + 4);
    printf("%d\n", s->searchInsert(v2, 2));

    int a3[] = {1,3,5,6}; 
    vector<int> v3(a3, a3 + 4);
    printf("%d\n", s->searchInsert(v3, 7));

    int a4[] = {1,3,5,6}; 
    vector<int> v4(a4, a4 + 4);
    printf("%d\n", s->searchInsert(v4, 0));

    int a5[] = {1}; 
    vector<int> v5(a5, a5 + 1);
    printf("%d\n", s->searchInsert(v5, 0));
}
