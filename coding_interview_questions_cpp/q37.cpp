/*
    37. 序列化二叉树

    请实现两个函数，分别用来序列化和反序列化二叉树。

    你需要设计一个算法来实现二叉树的序列化与反序列化。
    这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

    提示：
        输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。
        你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

    示例：
          1
         / \
        2   3
           / \
          4   5
        输入：root = [1,2,3,null,null,4,5]
        输出：[1,2,3,null,null,4,5]
    
    注意：本题与主站 297 题相同：https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof
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

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

# include <iostream>
# include <vector>
# include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    // bfs with queue
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "[]";

        string ans = "[";
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            if (q.front() != nullptr) {
                ans = ans + to_string(q.front()->val) + ",";
                q.push(q.front()->left);
                q.push(q.front()->right);
            } else 
                ans = ans + "null,";
            q.pop();
        }
        ans = ans.substr(0, ans.length() - 1) + "]";

        return ans;
    }

    // Decodes your encoded data to tree.
    // bfs with queue
    TreeNode* deserialize(string data) {
        if (data == "[]")
            return nullptr;
        data = data.substr(1, data.length() - 2) + ",";

        vector<TreeNode *> v;
        while (data.compare("")) {
            int index = data.find(",");
            string temp = data.substr(0, index);
            if (!temp.compare("null"))
                v.push_back(nullptr);
            else
                v.push_back(new TreeNode(atoi(temp.c_str())));
            data = data.substr(index + 1, data.length() - 1);
        }

        int i = 0;
        TreeNode *root = v[i];
        queue<TreeNode *> q;
        q.push(root);
        i++;
        while (!q.empty() && i < v.size()) {
            TreeNode *node = q.front();

            if (v[i] != nullptr) {
                node->left = v[i];
                q.push(node->left);
            }
            i++;

            if (v[i] != nullptr) {
                node->right = v[i];
                q.push(node->right);
            }
            i++;

            q.pop();
        }

        return root;
    }
};

int main() {
    Codec *c = new Codec();
    c->deserialize("[1,2,3,null,null,4,5]");
    
}