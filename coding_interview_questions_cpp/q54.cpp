/*
    54. 二叉搜索树的第k大节点

    给定一棵二叉搜索树，请找出其中第k大的节点。

    示例 1:
        输入: root = [3,1,4,null,2], k = 1
          3
         / \
        1  4
        \
        2
        输出: 4

    示例 2:
        输入: root = [5,3,6,2,4,null,null,1], k = 3
              5
             / \
            3  6
           / \
          2  4
         /
        1
        输出: 4

    限制：
        1 ≤ k ≤ 二叉搜索树元素个数

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof
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
# include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int ans = -1;       // k-th largest element
    int p = 0;          // k-th largest element's position as p

    // dfs
    int kthLargest(TreeNode* root, int k) {
        reversed_inorder_bfs(root, k);
        return ans;
    }

    void reversed_inorder_bfs(TreeNode *node, int k) {
        if (node == nullptr)
            return;

        reversed_inorder_bfs(node->right, k);       // dive in, right
        p++;                                        // one more element found
        if (p == k) {                               // k-th element found?
            ans = node->val;
            return;
        }  
        reversed_inorder_bfs(node->left, k);        // dive in, left
    }

    // iteration using stack
    int kthLargest2(TreeNode* root, int k){
        stack<TreeNode *> s;                        // stack simulation of dfs

        TreeNode *node = root;
        while (!s.empty() || node != nullptr) {
            while (node != nullptr) {               // dive in, right
                s.push(node);
                node = node->right;
            }

            p++;                                    // one more element found
            if (p == k)                             // k-th element found?
                return s.top()->val;                // return top if k-th element found

            node = s.top()->left;                   // dive in, left

            s.pop();                                // pop top
        }

        return -1;
    }
};

int main() {

}