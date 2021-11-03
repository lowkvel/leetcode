/*
    704. 二分查找

    给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

    示例 1:
        输入: nums = [-1,0,3,5,9,12], target = 9
        输出: 4
        解释: 9 出现在 nums 中并且下标为 4
    
    示例 2:
        输入: nums = [-1,0,3,5,9,12], target = 2
        输出: -1
        解释: 2 不存在 nums 中因此返回 -1
     
    提示：
        你可以假设 nums 中的所有元素是不重复的。
        n 将在 [1, 10000]之间。
        nums 的每个元素都将在 [-9999, 9999]之间。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/binary-search
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    // https://leetcode-cn.com/problems/binary-search/solution/er-fen-cha-zhao-xiang-jie-by-labuladong/ 
    int search(vector<int> &nums, int target) {
        int low = 0;                            // index of low initialized to 0
        int high = nums.size() - 1;             // index of high initialized to nums.size() - 1
        while (low <= high) {    
            /*
                the following two are equivalent, but the first one won't cause overflow (low + high -> way to big)
                mid = low + (high - low) / 2
                mid = (low + high) / 2
            */
            int mid = low + (high - low) / 2;   // mid calculation

            if (nums[mid] == target)            // found
                return mid;
            else if (nums[mid] > target)        // on the left
                high = mid - 1;
            else if (nums[mid] < target)        // on the right
                low = mid + 1;
        }
        return -1;                              // not found
    }
};

int main() {
    Solution *s = new Solution();

    int a1[] = {-1,0,3,5,9,12}; 
    vector<int> v1(a1, a1 + 9);
    printf("%d\n", s->search(v1, 9));

    int a2[] = {-1,0,3,5,9,12}; 
    vector<int> v2(a2, a2 + 9);
    printf("%d\n", s->search(v2, -2));
}
