/*
    700. 二叉搜索树中的搜索

    给定二叉搜索树（BST）的根节点和一个值。 
    你需要在BST中找到节点值等于给定值的节点。 
    返回以该节点为根的子树。 
    如果节点不存在，则返回 NULL。
    
    例如，

    给定二叉搜索树:
            4
           / \
          2   7
         / \
        1   3
    和值: 2

    你应该返回如下子树:
          2     
         / \   
        1   3

    在上述示例中，如果要找的值是 5，但因为没有节点值为 5，我们应该返回 NULL。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/search-in-a-binary-search-tree
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
    // bfs with queue
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr)
            return nullptr;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            if (q.front()->val == val) 
                return q.front();
            else if (q.front()->val > val) {
                if (q.front()->left != nullptr)
                    q.push(q.front()->left);
            } else {
                if (q.front()->right != nullptr)
                    q.push(q.front()->right);
            }

            q.pop();
        }

        return nullptr;
    }

    // dfs with stack
    TreeNode* searchBST2(TreeNode* root, int val) {
        if (root == nullptr) 
            return nullptr;

        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *node = s.top();
            s.pop();

            if (node->val == val)
                return node;
            else if (node->val > val) {
                if (node->left != nullptr)
                    s.push(node->left);
            } else {
                if (node->right != nullptr)
                    s.push(node->right);
            }
        }

        return nullptr;
    }

    // dfs with recursion
    TreeNode* searchBST3(TreeNode* root, int val) {
        if (root == nullptr || root->val == val)
            return root;

        return root->val > val ? searchBST3(root->left, val) : searchBST3(root->right, val);
    }
};

int main() {

}