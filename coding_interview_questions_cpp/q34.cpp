/*
    34. 二叉树中和为某一值的路径

    给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

    叶子节点 是指没有子节点的节点。

    示例 1：
        输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
        输出：[[5,4,11,2],[5,8,4,5]]

    示例 2：
        输入：root = [1,2,3], targetSum = 5
        输出：[]

    示例 3：
        输入：root = [1,2], targetSum = 0
        输出：[]

    提示：
        树中节点总数在范围 [0, 5000] 内
        -1000 <= Node.val <= 1000
        -1000 <= targetSum <= 1000
        注意：本题与主站 113 题相同：https://leetcode-cn.com/problems/path-sum-ii/

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

# include <iostream>
# include <vector>
# include <unordered_map>
# include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // dfs
    vector<vector<int> > pathSum(TreeNode* root, int target) {
        vector<vector<int> > ans;
        vector<int> path;
        recursion(root, target, path, ans);
        return ans;
    }

    void recursion(TreeNode *node, int target, vector<int> &path, vector<vector<int> > &ans) {
        if (node == nullptr)
            return;

        path.push_back(node->val);                                                      // add to path
        if (node->left == nullptr && node->right == nullptr && target == node->val)     // leaf and target reached
            ans.push_back(path);
        recursion(node->left, target - node->val, path, ans);                           // dive in, going left
        recursion(node->right, target - node->val, path, ans);                          // dive in, going right
        path.pop_back();                                                                // backtrack
    }

    // bfs
    vector<vector<int> > pathSum(TreeNode* root, int target) {
        vector<vector<int> > ans;
        unordered_map<TreeNode *, TreeNode *> umap;     // <node, node's parent>

        if (root == nullptr)
            return ans;

        queue<pair<TreeNode *, int> > q;                // <node, accumulated sum till here>
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            TreeNode *node = q.front().first;
            int acc_sum = q.front().second;
            if (node->left == nullptr && node->right == nullptr) {          // leaf here
                if (acc_sum + node->val == target)                          // target reached
                    trackPath(node, ans, umap);                             // track path from leaf to root
            } else {
                if (node->left != nullptr) {                                // left subtree not null
                    umap[node->left] = node;                                // <left child, current node>
                    q.push(make_pair(node->left, acc_sum + node->val));     // <current node, accumulated sum till here>
                }
                if (node->right != nullptr) {                               // right subtree not null
                    umap[node->right] = node;                               // <right child, current node>
                    q.push(make_pair(node->right, acc_sum + node->val));    // <current node, accumulated sum till here>
                }
            }
            q.pop();
        }

        return ans;
    }

    void trackPath(TreeNode *node, vector<vector<int> > &ans, unordered_map<TreeNode *, TreeNode *> &umap) {
        vector<int> path;
        while (node != nullptr) {
            path.push_back(node->val);
            node = umap[node];
        }
        reverse(path.begin(), path.end());  // reverse 
        ans.push_back(path);
    }
};

int main() {

}