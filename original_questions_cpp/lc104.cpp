/*
    104. 二叉树的最大深度

    给定一个二叉树，找出其最大深度。

    二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

    说明: 
        叶子节点是指没有子节点的节点。

    示例：
        给定二叉树 [3,9,20,null,null,15,7]，
             3
            / \
           9  20
         /  \
        15   7
        返回它的最大深度 3 。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree
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
    // bfs
    int maxDepth(TreeNode* root) {
        int ans = 0;
        if (root == nullptr)
            return ans;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            ans++;
            int qSize = q.size();   
            for (int i = 0; i < qSize; i++) {
                if (q.front()->left != nullptr)
                    q.push(q.front()->left);
                if (q.front()->right != nullptr)
                    q.push(q.front()->right);
                q.pop();
            }
        }

        return ans;
    }

    // dfs with recursion
    int maxDepth3(TreeNode* root) {
        if (root == nullptr)
            return 0;

        return max(maxDepth3(root->left), maxDepth3(root->right)) + 1;
    }
};

int main() {

}