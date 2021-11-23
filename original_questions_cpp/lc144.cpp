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

    // morris traversal
    /*
        Morris 遍历的核心思想是利用树的大量空闲指针，实现空间开销的极限缩减。其前序遍历规则总结如下：

        1. 新建临时节点，令该节点为 root；
        2. 如果当前节点的左子节点为空，将当前节点加入答案，并遍历当前节点的右子节点；
        3. 如果当前节点的左子节点不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点：
            1. 如果前驱节点的右子节点为空，将前驱节点的右子节点设置为当前节点。然后将当前节点加入答案，并将当前节点更新为当前节点的左子节点。
            2. 如果前驱节点的右子节点为当前节点，将它的右子节点重新设为空。当前节点更新为当前节点的右子节点。
        4. 重复步骤 2 和步骤 3，直到遍历结束。

        作者：LeetCode-Solution
        链接：https://leetcode-cn.com/problems/binary-tree-preorder-traversal/solution/er-cha-shu-de-qian-xu-bian-li-by-leetcode-solution/
        来源：力扣（LeetCode）
        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    */
    vector<int> preorderTraversal3(TreeNode* root) {
        
    }
};

int main() {

}
