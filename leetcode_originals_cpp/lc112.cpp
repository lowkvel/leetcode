/*
    112. 路径总和

    给你二叉树的根节点 root 和一个表示目标和的整数 targetSum ，判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。
    叶子节点 是指没有子节点的节点。

    示例 1：
              5
             / \
            4   8
           /   / \
         11  13   4
         / \       \
        7   2       1
        输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
        输出：true

    示例 2：
          1
         / \
        2   3
        输入：root = [1,2,3], targetSum = 5
        输出：false

    示例 3：
        输入：root = [1,2], targetSum = 0
        输出：false
     
    提示：
        树中节点的数目在范围 [0, 5000] 内
        -1000 <= Node.val <= 1000
        -1000 <= targetSum <= 1000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/path-sum
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
# include <queue>
# include <stack>

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
    // bfs with queue
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            if (q.front()->left == nullptr &&       // has to be leaf
                q.front()->right == nullptr &&      // has to be leaf
                q.front()->val == targetSum)        // match
                    return true;

            if (q.front()->left != nullptr) {
                q.front()->left->val = q.front()->left->val + q.front()->val;
                q.push(q.front()->left);
            }
            if (q.front()->right != nullptr) {
                q.front()->right->val = q.front()->right->val + q.front()->val;
                q.push(q.front()->right);
            }

            q.pop();
        }

        return false;
    }

    // dfs with stack
    bool hasPathSum2(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;

        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *left = s.top()->left;
            TreeNode *right = s.top()->right;
            int currentVal = s.top()->val;
            s.pop();

            if (left == nullptr && right == nullptr && currentVal == targetSum)
                    return true;
            
            if (left != nullptr) {
                left->val = left->val + currentVal;
                s.push(left);
            }
            if (right != nullptr) {
                right->val = right->val + currentVal;
                s.push(right);
            }
        }

        return false;
    }

    // dfs with recursion
    bool hasPathSum3(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;

        if (root->left == nullptr && root->right == nullptr)    // has to be leaf
            return root->val == targetSum;                      // match or not

        return hasPathSum3(root->left, targetSum - root->val) || hasPathSum3(root->right, targetSum - root->val);
    }
};

int main() {

}