/*
    98. 验证二叉搜索树

    给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

    有效 二叉搜索树定义如下：
        节点的左子树只包含 小于 当前节点的数。
        节点的右子树只包含 大于 当前节点的数。
        所有左子树和右子树自身必须也是二叉搜索树。
     
    示例 1：
          2
         / \
        1   3
        输入：root = [2,1,3]
        输出：true

    示例 2：
          5
         / \
        1   4
           / \
          3   6
        输入：root = [5,1,4,null,null,3,6]
        输出：false
        解释：根节点的值是 5 ，但是右子节点的值是 4 。
     
    提示：
        树中节点数目范围在[1, 104] 内
        -231 <= Node.val <= 231 - 1

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/validate-binary-search-tree
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
    // bfs with queue, need fix
    /*
       5
     4   6
    . . 3 7
    */
    bool isValidBST(TreeNode* root) {
        if (root == nullptr)
            return false;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            if (q.front()->left != nullptr) {
                if (q.front()->left->val < q.front()->val) 
                    q.push(q.front()->left);
                else 
                    return false;
            }

            if (q.front()->right != nullptr) {
                if (q.front()->right->val > q.front()->val) 
                    q.push(q.front()->right);
                else 
                    return false;
            }

            q.pop();
        }

        return true;
    }

    // dfs with stack, need fix
    /*
       5
     4   6
    . . 3 7
    */
    bool isValidBST2(TreeNode* root) {
        if (root == nullptr)
            return false;

        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *node = s.top();
            s.pop();

            if (node->left == nullptr) {
                if (node->left->val < node->val)
                    s.push(node->left);
                else 
                    return false;
            }

            if (node->right == nullptr) {
                if (node->right->val > node->val)
                    s.push(node->right);
                else 
                    return false;
            }
        }

        return true;
    }

    // inorder traversal -> sorted 
    bool isValidBST3(TreeNode* root) {
        stack<TreeNode *> s;
        long inorder = (long) INT_MIN - 1;
        while (!s.empty() || root != nullptr) {
            while (root != nullptr) {
                s.push(root);
                root = root->left;
            }

            root = s.top();
            s.pop();

            if (root->val <= inorder)   // comparison happens here, current val must be larger than previous val
                return false;

            inorder = root->val;
            root = root->right;
        }
        return true;
    }

    // dfs with recursion
    bool isValidBST4(TreeNode* root) {
        return dfs3(root, LONG_MIN, LONG_MAX);
    }

    bool dfs3(TreeNode *root, long low, long high) {
        if (root == nullptr)
            return true;

        if (root->val <= low || root->val >= high)  // outside of desired range
            return false;

        // recursion with left & right subtree with updated range
        return dfs3(root->left, low, root->val) && dfs3(root->right, root->val, high);   
    }
};

int main() {

}
