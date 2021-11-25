/*
    7. 重建二叉树

    输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。
    假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

    示例 1:
        Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
        Output: [3,9,20,null,null,15,7]

    示例 2:
        Input: preorder = [-1], inorder = [-1]
        Output: [-1]
     
    限制：
        0 <= 节点个数 <= 5000

    注意：本题与主站 105 题重复：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof
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
# include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // recursion
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> umap;               // <element, index> for inorder
        for (int i = 0; i < inorder.size(); i++)    // build hash map
            umap[inorder[i]] = i;

        return build(preorder, inorder, umap, 
                     0, preorder.size() - 1,        // [0, size - 1]
                     0, inorder.size() - 1);        // [0, size - 1]
    }

    TreeNode* build(const vector<int> &preorder, const vector<int> &inorder, unordered_map<int, int> &umap, 
                    int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right)
            return nullptr;

        int preorder_root = preorder_left;                          // index of the first node from preorder is the root
        int inorder_root = umap[preorder[preorder_root]];           // find index of root from inorder using umap
        
        TreeNode *root = new TreeNode(preorder[preorder_root]);     // build root
        int size_of_left_subtree = inorder_root - inorder_left;
        root->left  = build(preorder, inorder, umap, 
                            preorder_left + 1, preorder_left + size_of_left_subtree,    // [pl + 1, pl + sols], starting from root + 1 to root + size of left sub tree
                            inorder_left, inorder_root - 1);                            // [il, ir - 1], starting from left to root - 1
        root->right = build(preorder, inorder, umap,
                            preorder_left + size_of_left_subtree + 1, preorder_right,   // [pl + sols + 1, pr], starting from end of left subtree to right most
                            inorder_root + 1, inorder_right);                           // [ir + 1, ir], starting from root + 1 to right most
        return root;
    }

    // iteration
    TreeNode* buildTree2(vector<int>& preorder, vector<int>& inorder) {

        return nullptr;
    }
};

int main() {

}
