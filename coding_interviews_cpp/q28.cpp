/*
    对称的二叉树

    请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

    例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
            1
           / \
          2   2
         / \ / \
        3  4 4  3

    但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
            1
           / \
          2   2
           \   \
           3    3

    示例 1：
        输入：root = [1,2,2,3,4,4,3]
        输出：true

    示例 2：
        输入：root = [1,2,2,null,3,null,3]
        输出：false
     
    限制：
        0 <= 节点个数 <= 1000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root == nullptr ? true : recursion(root->left, root->right);
    }

    bool recursion(TreeNode *a, TreeNode *b) {
        if (a == nullptr && b == nullptr)   // both null, match
            return true;
        
        if (a == nullptr || b == nullptr)   // mismatch
            return false;

        if (a->val != b->val)               // mismatch
            return false;

        return recursion(a->left, b->right) && recursion(a->right, b->left);    // dive in
    }
};

int main() {

}