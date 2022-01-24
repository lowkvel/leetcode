/*
    189. 旋转数组

    给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
    
    示例 1:
        输入: nums = [1,2,3,4,5,6,7], k = 3
        输出: [5,6,7,1,2,3,4]
        解释:
        向右旋转 1 步: [7,1,2,3,4,5,6]
        向右旋转 2 步: [6,7,1,2,3,4,5]
        向右旋转 3 步: [5,6,7,1,2,3,4]

    示例 2:
        输入：nums = [-1,-100,3,99], k = 2
        输出：[3,99,-1,-100]
        解释: 
        向右旋转 1 步: [99,-1,-100,3]
        向右旋转 2 步: [3,99,-1,-100]
     
    提示：
        1 <= nums.length <= 2 * 104
        -231 <= nums[i] <= 231 - 1
        0 <= k <= 105

    进阶：
        尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
        你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/rotate-array
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    // use additional array, new index is (i+k)%n
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
            ans[(i + k) % n] = nums[i];
        nums.assign(ans.begin(), ans.end());
    }

    // ring-like substitution, math
    void rotate2(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int count = gcd(k, n);

        for (int start = 0; start < count; ++start) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % n;
                swap(nums[next], prev);
                current = next;
            } while (start != current);
        }
    }

    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }

    // triple rotate
    void rotate3(vector<int>& nums, int k) {
        // update k
        k = k % nums.size();

        // [0, n - 1] reverse
        int head = 0;
        int tail = nums.size() - 1;
        while (head < tail) {
            swap(nums[head], nums[tail]);
            head++;
            tail--;
        }

        // [0, k - 1] reverse
        head = 0;
        tail = k - 1;
        while (head < tail) {
            swap(nums[head], nums[tail]);
            head++;
            tail--;
        }

        // [k, n - 1] reverse
        head = k;
        tail = nums.size() - 1;
        while (head < tail) {
            swap(nums[head], nums[tail]);
            head++;
            tail--;
        }
    }
};

int main() {
    Solution *s = new Solution();

}
