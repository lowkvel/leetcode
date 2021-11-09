/*
    从上到下打印二叉树

    请实现一个函数按照之字形顺序打印二叉树，
    即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，
    其他行以此类推。

    例如:
        给定二叉树: [3,9,20,null,null,15,7],

          3
         / \
        9  20
          /  \
         15   7

    返回其层次遍历结果：
        [
        [3],
        [20,9],
        [15,7]
        ]
     
    提示：
        节点总数 <= 1000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。    
*/

# include <iostream>
# include <vector>
# include <queue>
# include <deque>

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
    // reverse at last
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if (root == nullptr)
            return ans;

        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> temp;                           // temp level-wise storage
            int tempSize = q.size();
            for (int i = 0; i < tempSize; i++) {        // loop from 0 to current level's size
                temp.push_back(q.front()->val);

                if (q.front()->left != nullptr)         // newly pushed left node wont be accessed at this level
                    q.push(q.front()->left);
                if (q.front()->right != nullptr)        // newly pushed right node wont be accessed at this level
                    q.push(q.front()->right);

                q.pop();                                // pop current node
            }

            if (ans.size() % 2 == 1)                    // reverse if existing level is odd (current level is even)
                reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }

        return ans;
    }

    // reverse at insert into current level
    vector<vector<int> > levelOrder2(TreeNode* root) {
        vector<vector<int> > ans;
        if (root == nullptr)
            return ans;

        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> temp;                           // temp level-wise storage
            int tempSize = q.size();
            for (int i = 0; i < tempSize; i++) {        // loop from 0 to current level's size
                // reverse insert if existing level is odd (current level is even)
                if (ans.size() % 2 == 1)                        // current level is even, insert at front
                    temp.insert(temp.begin(), q.front()->val);
                else                                            // current level is odd, push at back
                    temp.push_back(q.front()->val);

                if (q.front()->left != nullptr)         // newly pushed left node wont be accessed at this level
                    q.push(q.front()->left);
                if (q.front()->right != nullptr)        // newly pushed right node wont be accessed at this level
                    q.push(q.front()->right);

                q.pop();                                // pop current node
            }

            ans.push_back(temp);
        }

        return ans;
    }

    // reverse at insert into current level
    vector<vector<int> > levelOrder3(TreeNode* root) {
        vector<vector<int> > ans;
        if (root == nullptr)
            return ans;

        deque<TreeNode *> dq;
        dq.push_back(root);
        while (!dq.empty()) {
            vector<int> temp;                               // temp level-wise storage
            int tempSize = dq.size();

            for (int i = 0; i < tempSize; i++) 
                if (ans.size() % 2 == 0) {                  // current level is odd
                    temp.push_back(dq.front()->val);        // read from left of dq for current level
                    if (dq.front()->left != nullptr)        // push left node into deque at right
                        dq.push_back(dq.front()->left);
                    if (dq.front()->right != nullptr)       // push right node into deque at right
                        dq.push_back(dq.front()->right);
                    dq.pop_front();
                } else {                                    // current level is even
                    temp.push_back(dq.back()->val);         // read from right of dq for current level
                    if (dq.back()->right != nullptr)        // push right node into deque at left
                        dq.push_front(dq.back()->right);
                    if (dq.back()->left != nullptr)         // push left node into deque at left
                        dq.push_front(dq.back()->left);
                    dq.pop_back();
                }
            
            ans.push_back(temp);
        }

        return ans;
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

    TreeNode *n6 = new TreeNode(1);
    TreeNode *n7 = new TreeNode(2);
    TreeNode *n8 = new TreeNode(3);
    TreeNode *n9 = new TreeNode(4);
    TreeNode *n10 = new TreeNode(5);
    n6->left = n7;
    n6->right = n8;
    n7->left = n9;
    n8->right = n10;

    s->levelOrder3(n6);
}

/*
       1            0
   2       3        1
 4   n   n   5      2
6 7 n n 8 9 n n     3
*/