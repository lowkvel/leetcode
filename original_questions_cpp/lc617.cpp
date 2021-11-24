/*
    617. 合并二叉树

    给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。
    你需要将他们合并为一个新的二叉树。
    合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。

    示例 1:

    输入: 
        Tree 1                     Tree 2                  
            1                         2                             
           / \                       / \                            
          3   2                     1   3                        
         /                           \   \                      
        5                             4   7     

    输出: 合并后的树:
            3
           / \
          4   5
         / \   \ 
        5   4   7

    注意: 合并必须从两个树的根节点开始。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/merge-two-binary-trees
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr)
            return root2;
        if (root2 == nullptr)
            return root1;

        queue<pair<TreeNode *, TreeNode *> > q;
        q.push(make_pair(root1, root2));
        while (!q.empty()) {
            TreeNode *cur1 = q.front().first;
            TreeNode *cur2 = q.front().second;
            q.pop();

            cur1->val = cur1->val + cur2->val;

            if (cur1->left != nullptr && cur2->left != nullptr)
                q.push(make_pair(cur1->left, cur2->left));
            else if (cur1->left == nullptr && cur2->left != nullptr) {
                cur1->left = cur2->left;
                cur2->left = nullptr;
            } else if (cur1->left != nullptr && cur2->left == nullptr) {
                // do nothing, cur1's left already here and cur2's left is null
            } else {
                // do nothing, both null
            }

            if (cur1->right != nullptr && cur2->right != nullptr)
                q.push(make_pair(cur1->right, cur2->right));
            else if (cur1->right == nullptr && cur2->right != nullptr) {
                cur1->right = cur2->right;
                cur2->right = nullptr;
            } else if (cur1->right != nullptr && cur2->right == nullptr) {
                // do nothing, cur1's right already here and cur2's right is null
            } else {
                // do nothing, both null
            }
        }

        return root1;
    }

    // bfs with recursion
    TreeNode* mergeTrees2(TreeNode* root1, TreeNode* root2) {

        return nullptr;
    }

    // dfs with stack
    TreeNode* mergeTrees3(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr)
            return root2;
        if (root2 == nullptr)
            return root1;

        stack<pair<TreeNode *, TreeNode *> > s;
        s.push(make_pair(root1, root2));
        while (!s.empty()) {
            TreeNode *cur1 = s.top().first;
            TreeNode *cur2 = s.top().second;
            s.pop();

            cur1->val = cur1->val + cur2->val;

            if (cur1->left != nullptr && cur2->left != nullptr)
                s.push(make_pair(cur1->left, cur2->left));
            else if (cur1->left == nullptr && cur2->left != nullptr) {
                cur1->left = cur2->left;
                cur2->left = nullptr;
            } else if (cur1->left != nullptr && cur2->left == nullptr) {
                // do nothing, cur1's left already here and cur2's left is null
            } else {
                // do nothing, both null
            }

            if (cur1->right != nullptr && cur2->right != nullptr)
                s.push(make_pair(cur1->right, cur2->right));
            else if (cur1->right == nullptr && cur2->right != nullptr) {
                cur1->right = cur2->right;
                cur2->right = nullptr;
            } else if (cur1->right != nullptr && cur2->right == nullptr) {
                // do nothing, cur1's left already here and cur2's left is null
            } else {
                // do nothing, both null
            }
        }

        return root1;
    }

    // dfs with recursion
    TreeNode* mergeTrees4(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr)
            return root2;
        if (root2 == nullptr)
            return root1;

        TreeNode *merged = new TreeNode(root1->val + root2->val);
        merged->left = mergeTrees4(root1->left, root2->left);
        merged->right = mergeTrees4(root1->right, root2->right);

        return merged;
    }


};

int main() {
    Solution *s = new Solution();

    TreeNode *n11 = new TreeNode(1);
    TreeNode *n121 = new TreeNode(3);
    TreeNode *n122 = new TreeNode(2);
    TreeNode *n131 = new TreeNode(5);
    n11->left = n121;
    n11->right = n122;
    n121->left = n131;

    TreeNode *n21 = new TreeNode(2);
    TreeNode *n221 = new TreeNode(1);
    TreeNode *n222 = new TreeNode(3);
    TreeNode *n232 = new TreeNode(4);
    TreeNode *n233 = new TreeNode(7);
    n21->left = n221;
    n21->right = n222;
    n221->right = n232;
    n222->right = n233;

    s->mergeTrees4(n11, n21);
}