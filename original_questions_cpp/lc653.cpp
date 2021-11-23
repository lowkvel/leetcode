/*
    653. 两数之和 IV - 输入 BST

    给定一个二叉搜索树 root 和一个目标结果 k，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。

    示例 1：
            5
           / \
          3   6
         / \   \
        2   4   7
        输入: root = [5,3,6,2,4,null,7], k = 9
        输出: true

    示例 2：
        输入: root = [5,3,6,2,4,null,7], k = 28
        输出: false

    示例 3：
        输入: root = [2,1,3], k = 4
        输出: true

    示例 4：
        输入: root = [2,1,3], k = 1
        输出: false

    示例 5：
        输入: root = [2,1,3], k = 3
        输出: true
     
    提示:
        二叉树的节点个数的范围是  [1, 10^4].
        -10^4 <= Node.val <= 10^4
        root 为二叉搜索树
        -10^5 <= k <= 10^5

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst
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
# include <unordered_set>

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
    // recursion with hashset
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> uset;
        return find(root, k, uset);
    }

    bool find(TreeNode *node, int k, unordered_set<int> &uset) {
        if (node == nullptr)
            return false;
        if (uset.count(k - node->val) > 0)  // previous added (k - node->val) exist, pair found
            return true;

        uset.insert(node->val);             // add current val into set

        return find(node->left, k, uset) || find(node->right, k, uset);     // search left or right
    }

    // bfs with hashset, similar to recursion with hashset
    bool findTarget2(TreeNode* root, int k) {
        if (root == nullptr)
            return false;

        unordered_set<int> uset;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) 
            if (uset.count(k - q.front()->val) > 0)
                return true;
            else {
                uset.insert(q.front()->val);

                if (q.front()->left != nullptr)
                    q.push(q.front()->left);
                if (q.front()->right != nullptr)
                    q.push(q.front()->right);

                q.pop();
            }
        return false;
    }

    // traverse bst with dual pointers
    bool findTarget3(TreeNode* root, int k) {
        vector<int> bst;
        inorder(root, bst);

        int left = 0;
        int right = bst.size() - 1;

        while (left < right) {
            if (bst[left] + bst[right] == k)
                return true;
            else if (bst[left] + bst[right] < k)
                left++;
            else
                right--;
        }

        return false;
    }

    void inorder(TreeNode *node, vector<int> &bst) {
        if (node == nullptr)
            return;

        inorder(node->left, bst);
        bst.push_back(node->val);
        inorder(node->right, bst);
    }
};

int main() {

}