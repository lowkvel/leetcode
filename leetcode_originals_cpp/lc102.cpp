/*
    102. 二叉树的层序遍历

    给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

    示例：
    二叉树：[3,9,20,null,null,15,7],
             3
            / \
           9  20
         /  \
        15   7
    返回其层序遍历结果：
        [
            [3],
            [9,20],
            [15,7]
        ]

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
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
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if (root == nullptr)
            return ans;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int currentLevelSize = q.size();
            ans.push_back(vector<int>());                   // initialize a level vector
            for (int i = 0; i < currentLevelSize; i++) {    // traverse current level
                ans.back().push_back(q.front()->val);       // push into level vector
                if (q.front()->left != nullptr)             // add left if exist
                    q.push(q.front()->left);
                if (q.front()->right != nullptr)            // add right if exist
                    q.push(q.front()->right);
                q.pop();                                    // pop current
            }
        }

        return ans;
    }
};

int main() {

}