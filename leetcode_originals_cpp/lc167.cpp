/*
    167. 两数之和II

    给定一个已按照 非递减顺序排列  的整数数组 numbers ，请你从数组中找出两个数满足相加之和等于目标数 target 。
    函数应该以长度为 2 的整数数组的形式返回这两个数的下标值。
    numbers 的下标 从 1 开始计数 ，所以答案数组应当满足 1 <= answer[0] < answer[1] <= numbers.length 。
    你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。

    示例 1：
        输入：numbers = [2,7,11,15], target = 9
        输出：[1,2]
        解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。

    示例 2：
        输入：numbers = [2,3,4], target = 6
        输出：[1,3]

    示例 3：
        输入：numbers = [-1,0], target = -1
        输出：[1,2]
     
    提示：
        2 <= numbers.length <= 3 * 104
        -1000 <= numbers[i] <= 1000
        numbers 按 非递减顺序 排列
        -1000 <= target <= 1000
        仅存在一个有效答案

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>
# include <unordered_map>

using namespace std;

class Solution {
public:
    // brute force
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i)
            for (int j = i + 1; j < numbers.size(); ++j) 
                if (numbers[i] + numbers[j] == target)
                    return {i + 1, j + 1};
        return {};
    }

    // map
    vector<int> twoSum2(vector<int>& numbers, int target) {
        unordered_map<int, int> umap;
        for (int i = 0; i < numbers.size(); i++) {
            if (umap.count(target - numbers[i]) != 0)
                return {umap[target - numbers[i]] + 1, i + 1};
            umap.insert(make_pair(numbers[i], i));
        }
        return {};
    }

    // binary search
    vector<int> twoSum3(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); i++) {
            int left = i + 1;                   // elements on the left of the left pointer is useless
            int right = numbers.size() - 1;     // search to the end
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (numbers[mid] + numbers[i] == target)
                    return {i + 1, mid + 1};
                else if (numbers[mid] + numbers[i] > target)
                    right = mid - 1;
                else if (numbers[mid] + numbers[i] < target)
                    left = mid + 1;
            }
        }
        return {};
    }

    // dual pointers
    /*
        使用双指针的实质是缩小查找范围。
        那么会不会把可能的解过滤掉？
        答案是不会。

        假设 numbers[i]+numbers[j]=target 是唯一解，其中 0 ≤ i < j ≤ numbers.length−1。
        初始时两个指针分别指向下标 0 和下标 numbers.length−1，左指针指向的下标小于或等于 i，右指针指向的下标大于或等于 j。

        除非初始时左指针和右指针已经位于下标 i 和 j，否则一定是左指针先到达下标 i 的位置或者右指针先到达下标 j 的位置。
        如果左指针先到达下标 i 的位置，此时右指针还在下标 j 的右侧，则 sum > target，因此一定是右指针左移，左指针不可能移到 i 的右侧。
        如果右指针先到达下标 j 的位置，此时左指针还在下标 i 的左侧，则 sum < target，因此一定是左指针右移，右指针不可能移到 j 的左侧。

        由此可见，在整个移动过程中，左指针不可能移到 i 的右侧，右指针不可能移到 j 的左侧，因此不会把可能的解过滤掉。

        作者：LeetCode-Solution
        链接：https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/solution/liang-shu-zhi-he-ii-shu-ru-you-xu-shu-zu-by-leet-2/
        来源：力扣（LeetCode）
        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    */
    vector<int> twoSum4(vector<int>& numbers, int target) {
        int head = 0;
        int tail = numbers.size() - 1;

        while (head < tail) 
            if (numbers[head] + numbers[tail] == target)        // found
                return {head + 1, tail + 1};
            else if (numbers[head] + numbers[tail] < target)    // increase a bit
                head++;
            else if (numbers[head] + numbers[tail] > target)    // decrease a bit
                tail--;

        return {};
    }
};

int main() {
    Solution *s = new Solution();

}
