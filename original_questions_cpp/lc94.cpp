/*
    94. 二叉树的中序遍历（左根右）

    给定一个二叉树的根节点 root ，返回它的 中序 遍历。

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
        输出：[2,1]

    示例 5：
        1
         \
          2
        输入：root = [1,null,2]
        输出：[1,2]
     
    提示：
        树中节点数目在范围 [0, 100] 内
        -100 <= Node.val <= 100
 
    进阶: 
        递归算法很简单，你可以通过迭代算法完成吗？

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }

    void inorder(TreeNode *node, vector<int> &ans) {
        if (node == nullptr)            // edge case
            return;
        inorder(node->left, ans);       // left
        ans.push_back(node->val);       // root
        inorder(node->right, ans);      // right
    }

    // iteration with stack
    vector<int> inorderTraversal2(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;

        stack<TreeNode *> stk;
        TreeNode *node = root;
        while (!stk.empty() || node != nullptr) {
            while (node != nullptr) {
                stk.push(node);             // push root into stack for later access
                node = node->left;          // move to added root's left
            }
            node = stk.top();               // go back to added root
            stk.pop();                      // pop added root from stack
            ans.push_back(node->val);       // add root's val into answer   <- here
            node = node->right;             // move to added root's right
        }

        return ans;
    }

    // morris traversal
    /*
        Morris 遍历算法整体步骤如下（假设当前遍历到的节点为 x）：

        1. 如果 x 无左孩子，先将 x 的值加入答案数组，再访问 x 的右孩子，即 x = x.right。
        2. 如果 x 有左孩子，则找到 x 左子树上最右的节点（即左子树中序遍历的最后一个节点，x 在中序遍历中的前驱节点），我们记为 predecessor。根据 predecessor 的右孩子是否为空，进行如下操作。
            1. 如果 predecessor 的右孩子为空，则将其右孩子指向 x，然后访问 x 的左孩子，即 x = x.left。
            2. 如果 predecessor 的右孩子不为空，则此时其右孩子指向 x，说明我们已经遍历完 x 的左子树，我们将 predecessor 的右孩子置空，将 x 的值加入答案数组，然后访问 x 的右孩子，即 x = x.right。
        3. 重复上述操作，直至访问完整棵树。

        作者：LeetCode-Solution
        链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/er-cha-shu-de-zhong-xu-bian-li-by-leetcode-solutio/
        来源：力扣（LeetCode）
        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    */
    vector<int> inorderTraversal3(TreeNode* root) {

    }
};

int main() {

}
