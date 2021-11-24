/*
    226. 翻转二叉树

    翻转一棵二叉树。

    示例：

    输入：
             4
           /   \
          2     7
         / \   / \
        1   3 6   9

    输出：
             4
           /   \
          7     2
         / \   / \
        9   6 3   1

    备注:
        这个问题是受到 Max Howell 的 原问题 启发的 ：
        谷歌：我们90％的工程师使用您编写的软件(Homebrew)，但是您却无法在面试时在白板上写出翻转二叉树这道题，这太糟糕了。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/invert-binary-tree
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
    // bfs with recursion
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        
        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);
        root->left = right;
        root->right = left;

        return root;
    }

    // iteration
    TreeNode* invertTree2(TreeNode* root) {
        if (root == nullptr)
            return nullptr;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *temp = q.front()->left;
            q.front()->left = q.front()->right;
            q.front()->right = temp;

            if (q.front()->left != nullptr)
                q.push(q.front()->left);
            if (q.front()->right != nullptr)
                q.push(q.front()->right);

            q.pop();
        }

        return root;
    }
};

int main() {

}