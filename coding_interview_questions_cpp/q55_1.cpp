/*
    55-1. 二叉树的深度

    输入一棵二叉树的根节点，求该树的深度。
    从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。

    例如：
        给定二叉树 [3,9,20,null,null,15,7]，
          3
         / \
        9  20
          /  \
         15   7
        返回它的最大深度 3 。

    提示：
        节点总数 <= 10000
        注意：本题与主站 104 题相同：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

# include <iostream>
# include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // bfs
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        queue<TreeNode *> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            depth++;                                // layer count increment
            int length = q.size();
            for (int i = 0; i < length; i++) {      // iterate through current layer
                if (q.front()->left != nullptr)     // push left into queue if exist
                    q.push(q.front()->left);
                if (q.front()->right != nullptr)    // push right into queue if exist
                    q.push(q.front()->right);
                q.pop();                            // pop current node
            }
        }

        return depth;
    }

    // dfs
    int maxDepth2(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return max(maxDepth2(root->left), maxDepth2(root->right)) + 1;
    }
};

int main() {

}