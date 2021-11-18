/*
    46. 全排列

    给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

    示例 1：
        输入：nums = [1,2,3]
        输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

    示例 2：
        输入：nums = [0,1]
        输出：[[0,1],[1,0]]

    示例 3：
        输入：nums = [1]
        输出：[[1]]
    
    提示：
        1 <= nums.length <= 6
        -10 <= nums[i] <= 10
        nums 中的所有整数 互不相同

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/permutations
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > ans;
        if (nums.size() == 0)
            return ans;

        vector<bool> used(nums.size(), false);      // track used element
        vector<int> path;                           // record path
        dfs(nums, nums.size(), 0, path, used, ans);

        return ans;
    }

    void dfs(vector<int> &nums, int len, int depth, vector<int> &path, vector<bool> &used, vector<vector<int> > &ans) {
        if (depth == len) {         // one permutation found
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < len; i++) 
            if (!used[i]) {
                path.push_back(nums[i]);
                used[i] = true;

                dfs(nums, len, depth + 1, path, used, ans);

                used[i] = false;
                path.pop_back();
            }
    }
};

int main() {
    Solution *s = new Solution();

    int a1[] = {1,2,3};
    vector<int> v1(a1, a1 + 3);
    
    s->permute(v1);
}