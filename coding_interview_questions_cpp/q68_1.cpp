/*
    68-1. 二叉树的最近公共祖先

    给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
    百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

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
        
    注意：本题与主站 235 题相同：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
    
    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

# include <iostream>
# include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // traverse twice to get two paths, then find lca
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> pathp = getPath(root, p);
        vector<TreeNode *> pathq = getPath(root, q);
        TreeNode *lca;
        for (int i = 0; i < pathp.size() && i < pathq.size(); i++)
            if (pathp[i]->val == pathq[i]->val)
                lca = pathp[i];
            else
                break;
        return lca;
    }

    vector<TreeNode *> getPath(TreeNode *node, TreeNode *target) {
        vector<TreeNode *> path;
        while (node != target) {
            path.push_back(node);
            if (node->val < target->val)
                node = node->right;
            else 
                node = node->left;
        }
        path.push_back(node);
        return path;
    }

    // traverse once, using property, the lca must be the first node splitting p and q
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *lca = root;
        while (true) 
            if (p->val > lca->val && q->val > lca->val)
                lca = lca->right;
            else if (p->val < lca->val && q->val < lca->val)
                lca = lca->left;
            else
                break;

        return lca;
    }
};

int main() {

}