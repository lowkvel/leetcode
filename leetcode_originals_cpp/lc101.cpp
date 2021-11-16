/*
    101. 对称二叉树
    
    给定一个二叉树，检查它是否是镜像对称的。
    例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
            1
           / \
          2   2
         / \ / \
        3  4 4  3
    
    但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
        1
       / \
      2   2
       \   \
        3    3
    
    进阶：
        你可以运用递归和迭代两种方法解决这个问题吗？

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/symmetric-tree
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
    bool isSymmetric(TreeNode* root) {
        return checkSymmetric(root, root);
    }

    bool checkSymmetric(TreeNode *u, TreeNode *v) {
        queue<TreeNode *> q;
        q.push(u);
        q.push(v);

        while (!q.empty()) {
            u = q.front(); q.pop();
            v = q.front(); q.pop();

            if (u == nullptr && v == nullptr)                       // both nullptr, check next two 
                continue;

            if ((u == nullptr || v == nullptr) || u->val != v->val) // one nullptr or not equal
                return false;

            q.push(u->left);
            q.push(v->right);

            q.push(u->right);
            q.push(v->left);
        }

        return true;
    }

    // recursion
    bool isSymmetric2(TreeNode* root) {
        return checkSymmetric2(root, root);
    }

    bool checkSymmetric2(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr)   // both nullptr
            return true;
        if (p == nullptr || q == nullptr)   // one nullptr
            return false;

        return p->val == q->val 
                && checkSymmetric2(p->left, q->right) && checkSymmetric2(p->right, q->left);    // no nullptr
    }
};

int main() {
    int x = 1;

    for (int i = 0; i < 3; i++) {
        cout << 1 << endl;
        
        cout << 1 << endl;
    }
}