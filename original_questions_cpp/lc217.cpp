/*
    217. 存在重复元素

    给定一个整数数组，判断是否存在重复元素。
    如果存在一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。

    示例 1:
        输入: [1,2,3,1]
        输出: true
    
    示例 2:
        输入: [1,2,3,4]
        输出: false
    
    示例 3:
        输入: [1,1,1,3,3,4,3,2,4,2]
        输出: true

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/contains-duplicate
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>
# include <unordered_set>

using namespace std;

class Solution {
public:
    // using characteristic of set, non-duplicates
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> uset;
        for (int i = 0; i < nums.size(); i++) {
            if (uset.count(nums[i]) > 0)
                return true;
            uset.insert(nums[i]);
        }
        return false;
    }

    // sort, then compare
    bool containsDuplicate2(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) 
            if (nums[i] == nums[i + 1])
                return true;
        return false;
    }
};

int main() {
    Solution *s = new Solution();

    int a1[] = {1,2,3,1}; 
    vector<int> v1(a1, a1 + 4);
    printf("%d\n", s->containsDuplicate(v1));

    int a2[] = {1,2,3,4}; 
    vector<int> v2(a2, a2 + 4);
    printf("%d\n", s->containsDuplicate(v2));

    int a3[] = {1,1,1,3,3,4,3,2,4,2}; 
    vector<int> v3(a3, a3 + 10);
    printf("%d\n", s->containsDuplicate(v3));
}
