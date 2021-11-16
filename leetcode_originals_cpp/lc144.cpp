/*
    144. 二叉树的前序遍历（根左右）

    给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

    示例 1：
        1
         \
          2
         /
        3
        输入：root = [1,null,2,3]
        输出：[1,2,3]

    示例 2：
        输入：root = []
        输出：[]

    示例 3：
        输入：root = [1]
        输出：[1]

    示例 4：
          1
         /
        2
        输入：root = [1,2]
        输出：[1,2]

    示例 5：
        1
         \
          2
        输入：root = [1,null,2]
        输出：[1,2]
     
    提示：
        树中节点数目在范围 [0, 100] 内
        -100 <= Node.val <= 100

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/binary-tree-preorder-traversal
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
    // recursion
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }

    void preorder(TreeNode *node, vector<int> &ans) {
        if (node == nullptr)            // edge case
            return;
        ans.push_back(node->val);       // root
        preorder(node->left, ans);      // left
        preorder(node->right, ans);     // right
    }
    
    // iteration with stack 
    vector<int> preorderTraversal2(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;

        stack<TreeNode *> stk;
        TreeNode *node = root;
        while (!stk.empty() || node != nullptr) {
            while (node != nullptr) {
                ans.push_back(node->val);   // add root's val to answer     <- here
                stk.push(node);             // push added root into stack
                node = node->left;          // move to added root's left
            }
            node = stk.top();               // go back to added root
            stk.pop();                      // pop added root from stack
            node = node->right;             // move to added root's right
        }

        return ans;
    }
};

int main() {

}
