/*
    235. 二叉搜索树的最近公公祖先

    给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

    最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

    例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]

    示例 1:
        输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
        输出: 6 
        解释: 节点 2 和节点 8 的最近公共祖先是 6。

    示例 2:
        输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
        输出: 2
        解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
     
    说明:
        所有节点的值都是唯一的。
        p、q 为不同节点且均存在于给定的二叉搜索树中。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree
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
    // traverse twice, firstly get two paths, secondly find lca
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> pathp; getPath(root, p, pathp);
        vector<TreeNode *> pathq; getPath(root, q, pathq);

        TreeNode *lca = root;
        for (int i = 0; i < pathp.size() && i < pathq.size(); i++)  // short first
            if (pathp[i] == pathq[i])
                lca = pathp[i];
            else
                break;
        return lca;
    }

    void getPath(TreeNode *root, TreeNode *target, vector<TreeNode *> &path) {
        TreeNode *node = root;

        // path finder
        while (node != nullptr) {
            path.push_back(node);               // push current node into vector

            if (node->val > target->val)        // left
                node = node->left;
            else if (node->val < target->val)   // right
                node = node->right;
            else                                // found
                break;
        }
    }

    // traverse once, iteration implementation, search for both target at same time
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *lca = root;

        while (lca != nullptr) 
            if (lca->val > p->val && lca->val > q->val)         // both targets smaller than current node, move lca to the left
                lca = lca->left;
            else if (lca->val < p->val && lca->val < q->val)    // both targets larger than current node, move lca to the right
                lca = lca->right;
            else                                                // targets split here, lca is current node
                break;

        return lca;
    }

    // traverse once, recursion implementation, search for both target at same time
    TreeNode* lowestCommonAncestor3(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ((root->val - p->val) * (root->val - q->val) <= 0)   // targets spilit here, root is lca
            return root;

        return lowestCommonAncestor3(root->val > p->val ? root->left : root->right, p, q);  // same side, dive in
    }

    // common solution, no matter the tree is bst or not
    TreeNode* lowestCommonAncestor4(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) 
            return root;
        
        TreeNode *left = lowestCommonAncestor4(root->left, p, q);
        TreeNode *right = lowestCommonAncestor4(root->right, p, q);

        if (left == nullptr)    // left is null, both targets on root's right side
            return right;
        if (right == nullptr)   // right is null, both targets on root's left side
            return left;

        return root;            // splits here, return root
    }
};

int main() {

}