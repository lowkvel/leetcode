/*
    1. 两数之和

    给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
    你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
    你可以按任意顺序返回答案。

    示例 1：
        输入：nums = [2,7,11,15], target = 9
        输出：[0,1]
        解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

    示例 2：
        输入：nums = [3,2,4], target = 6
        输出：[1,2]

    示例 3：
        输入：nums = [3,3], target = 6
        输出：[0,1]
    
    提示：
        2 <= nums.length <= 104
        -109 <= nums[i] <= 109
        -109 <= target <= 109
        只会存在一个有效答案

    进阶：
        你可以想出一个时间复杂度小于 O(n2) 的算法吗？

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/two-sum
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>
# include <map>

using namespace std;

class Solution {
public:
    // brute force
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i)
            for (int j = i + 1; j < nums.size(); ++j) 
                if (nums[i] + nums[j] == target)
                    return {i, j};
        return {};
    }

    // map
    vector<int> twoSum2(vector<int>& nums, int target) {
        map<int, int> m;                                                // map[value, index]
        for (int i = 0; i < nums.size(); i++) {
            map<int, int>::iterator pos = m.find(target - nums[i]);     // find if visited
            if (pos != m.end())                                         // found
                return {pos->second, i};                                // return {index, index}
            m.insert(make_pair(nums[i], i));                            // insert {value, index}
        }
        return {};
    }
};

int main() {
    Solution *s = new Solution();

    int a1[] = {2,7,11,15}; 
    vector<int> v1(a1, a1 + 4);
    vector<int> r1(s->twoSum2(v1, 9));
    printf("%d, %d\n", r1[0], r1[1]);

    int a2[] = {3,2,4}; 
    vector<int> v2(a2, a2 + 3);
    vector<int> r2(s->twoSum2(v2, 6));
    printf("%d, %d\n", r2[0], r2[1]);

    int a3[] = {3,3}; 
    vector<int> v3(a3, a3 + 4);
    vector<int> r3(s->twoSum2(v3, 6));
    printf("%d, %d\n", r3[0], r3[1]);
}
