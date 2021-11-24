/*
    55-2. 平衡二叉树

    输入一棵二叉树的根节点，判断该树是不是平衡二叉树。
    如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

    示例 1:
        给定二叉树 [3,9,20,null,null,15,7]
          3
         / \
        9  20
          /  \
         15   7
        返回 true 。

    示例 2:
        给定二叉树 [1,2,2,3,3,null,null,4,4]
              1
             / \
            2   2
           / \
          3   3
         / \
        4   4
        返回 false 。

    限制：
        0 <= 树的结点个数 <= 10000
        注意：本题与主站 110 题相同：https://leetcode-cn.com/problems/balanced-binary-tree/

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof
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

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // dfs, postorder (left -> right -> root)
    bool isBalanced(TreeNode* root) {
        return recursion(root) != -1;
    }

    int recursion(TreeNode *node) {
        if (node == nullptr)                    // leaf reached with depth 0
            return 0;

        int left = recursion(node->left);       // dive in to get left subtree's depth
        if (left == -1)                         // optimization here
            return -1;

        int right = recursion(node->right);     // dive in to get right subtree's depth
        if (right == -1)                        // optimization here
            return -1;

        return abs(left - right) <= 1 ? max(left, right) + 1 : -1;  // return -1 if difference is greater than 1
    }

    // dfs, preorder, massive repeated calculation 
    bool isBalanced2(TreeNode* root) {
        if (root == nullptr)
            return true;

        return abs(depth(root->left) - depth(root->right)) <= 1 && 
               isBalanced2(root->left) && isBalanced2(root->right);
    }

    int depth(TreeNode *node) {
        if (node == nullptr)
            return 0;
        
        return max(depth(node->left), depth(node->right)) + 1;
    }
};

int main() {

}