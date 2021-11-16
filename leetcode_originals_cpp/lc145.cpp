/*
    145. 二叉树的后序遍历（左右根）

    给定一个二叉树，返回它的 后序 遍历。

    示例:
    输入: [1,null,2,3]  
        1
         \
          2
         /
        3 
    输出: [3,2,1]

    进阶: 
        递归算法很简单，你可以通过迭代算法完成吗？

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }

    void postorder(TreeNode *node, vector<int> &ans) {
        if (node == nullptr)            // edge case
            return;
        postorder(node->left, ans);     // left
        postorder(node->right, ans);    // right
        ans.push_back(node->val);       // root
    }

    // iteration
    vector<int> postorderTraversal2(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;

        stack<TreeNode *> stk;
        TreeNode *node = root;
        TreeNode *prev = nullptr;
        while (!stk.empty() || node != nullptr) {
            while (node != nullptr) {
                stk.push(node);             // push root into stack for later access
                node = node->left;          // move to root's left
            }

            node = stk.top();               // go back to added root
            stk.pop();                      // pop added root from stack

            if (node->right == nullptr      // no right subtree, left traversd, no right subtree, now root
                || node->right == prev) {   // right subtree is traversed if node->right == prev, left & right all traversed, now root
                ans.push_back(node->val);   // add root's val into answer       <- here
                prev = node;                // move one level up from right
                node = nullptr;             // prevent repeated left subtree visiting (wont go into while loop above)
            } else {
                stk.push(node);             // push root into stack for later access
                node = node->right;         // move to root's right
            }
        }

        return ans;
    }

    // morris traversal
    /*
        Morris 遍历的核心思想是利用树的大量空闲指针，实现空间开销的极限缩减。其后序遍历规则总结如下：

        1. 新建临时节点，令该节点为 root；
        2. 如果当前节点的左子节点为空，则遍历当前节点的右子节点；
        3. 如果当前节点的左子节点不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点；
            1. 如果前驱节点的右子节点为空，将前驱节点的右子节点设置为当前节点，当前节点更新为当前节点的左子节点。
            2. 如果前驱节点的右子节点为当前节点，将它的右子节点重新设为空。倒序输出从当前节点的左子节点到该前驱节点这条路径上的所有节点。当前节点更新为当前节点的右子节点。
        4. 重复步骤 2 和步骤 3，直到遍历结束。

        作者：LeetCode-Solution
        链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/er-cha-shu-de-hou-xu-bian-li-by-leetcode-solution/
        来源：力扣（LeetCode）
        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    */
    vector<int> postorderTraversal3(TreeNode* root) {

    }
};

int main() {

}