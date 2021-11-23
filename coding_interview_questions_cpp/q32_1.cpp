/*
    从上到下打印二叉树

    从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

    例如:
        给定二叉树: [3,9,20,null,null,15,7],

          3
         / \
        9  20
          /  \
         15   7

    返回：
        [3,9,20,15,7]
     
    提示：
        节点总数 <= 1000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。    
*/

# include <iostream>
# include <vector>
# include <queue>

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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr)                    // empty tree
            return ans;

        queue<TreeNode *> q;
        q.push(root);                           // push root into queue
        while (!q.empty()) {
            ans.push_back(q.front()->val);      // push back current node's val

            if (q.front()->left != nullptr)     // push left into queue if not null
                q.push(q.front()->left);
            if (q.front()->right != nullptr)    // push right into queue if not null
                q.push(q.front()->right);

            q.pop();                            // pop current node from queue
        }

        return ans;                             // return it
    }
};

int main() {
    Solution *s = new Solution();

    TreeNode *n1 = new TreeNode(3);
    TreeNode *n2 = new TreeNode(9);
    TreeNode *n3 = new TreeNode(20);
    TreeNode *n4 = new TreeNode(15);
    TreeNode *n5 = new TreeNode(7);
    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

    s->levelOrder(n1);
}
