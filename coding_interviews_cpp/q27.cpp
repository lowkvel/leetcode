/*
    二叉树的镜像

    请完成一个函数，输入一个二叉树，该函数输出它的镜像。

    例如输入：
             4
           /   \
          2     7
         / \   / \
        1   3 6   9

    镜像输出：
             4
           /   \
          7     2
         / \   / \
        9   6 3   1

    示例 1：
        输入：root = [4,2,7,1,3,6,9]
        输出：[4,7,2,9,6,3,1]
     
    限制：
        0 <= 节点个数 <= 1000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <stack>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        // edge case, return
        if (root == nullptr)
            return nullptr;

        // swap
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;

        // recursion
        mirrorTree(root->left);
        mirrorTree(root->right);

        // return
        return root;
    }

    TreeNode* mirrorTree2(TreeNode* root) {
        // edge case, return
        if (root == nullptr)
            return nullptr;

        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *node = s.top();
            s.pop();
            
            if (node->left != nullptr)
                s.push(node->left);
            if (node->right != nullptr)
                s.push(node->right);
            
            TreeNode *temp = node->left;
            node->left = node->right;
            node->right = temp;
        }

        // return
        return root;
    }
};

int main() {

}