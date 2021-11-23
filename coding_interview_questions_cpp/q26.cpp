/*
    树的子结构

    输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
    B是A的子结构， 即 A中有出现和B相同的结构和节点值。

    例如:
        给定的树 A:

             3
            / \
           4   5
          / \
         1   2
        给定的树 B：

           4 
          /
         1
        返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。

    示例 1：
        输入：A = [1,2,3], B = [3,1]
        输出：false

    示例 2：
        输入：A = [3,4,5,1,2], B = [4,1]
        输出：true

    限制：
        0 <= 节点个数 <= 10000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof
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

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        return (A != nullptr && B != nullptr) && 
                (recursion(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
    }

    bool recursion(TreeNode *a, TreeNode *b) {
        if (b == nullptr)       // subtree emptied, match found
            return true;

        if (a == nullptr)       // source tree emptied, mismatch
            return false;

        if (a->val != b->val)   // root node mismatch
            return false;

        return recursion(a->left, b->left) && recursion(a->right, b->right);    // go for left and right
    }
};

int main() {
    Solution *s = new Solution();

    TreeNode *n1 = new TreeNode(3);
    TreeNode *n2 = new TreeNode(4);
    TreeNode *n3 = new TreeNode(5);
    TreeNode *n4 = new TreeNode(1);
    TreeNode *n5 = new TreeNode(2);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;

    TreeNode *n6 = new TreeNode(4);
    TreeNode *n7 = new TreeNode(1);
    n6->left = n7;

    s->isSubStructure(n1, n6);
}