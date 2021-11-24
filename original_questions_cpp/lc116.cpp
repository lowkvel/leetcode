/*
    116. 填充每个节点的下一个右侧节点指针

    给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
        struct Node {
            int val;
            Node *left;
            Node *right;
            Node *next;
        }
    填充它的每个 next 指针，让这个指针指向其下一个右侧节点。
    如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
    初始状态下，所有 next 指针都被设置为 NULL。

    进阶：
        你只能使用常量级额外空间。
        使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
         
    示例：
        输入：root = [1,2,3,4,5,6,7]
        输出：[1,#,2,3,#,4,5,6,7,#]
        解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。序列化的输出按层序遍历排列，同一层节点由 next 指针连接，'#' 标志着每一层的结束。
         

    提示：
        树中节点的数量少于 4096
        -1000 <= node.val <= 1000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

# include <iostream>
# include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    // bfs with queue
    Node* connect(Node* root) {
        if (root == nullptr)
            return root;
        
        queue<pair<Node *, int> > q;                        // queue with < Node *, level >, or use for loop with level's size()
        q.push(make_pair(root, 1));
        while (!q.empty()) {
            Node *cur = q.front().first;
            int curl = q.front().second;
            q.pop();
            
            if (!q.empty() && q.front().second == curl)     // same level, update ->next to queue.front()
                    cur->next = q.front().first;
            
            if (cur->left != nullptr)                       // push left into queue with level + 1
                q.push(make_pair(cur->left, curl + 1));
            if (cur->right != nullptr)                      // push right into queue with level + 1
                q.push(make_pair(cur->right, curl + 1));
        }
    
        return root;
    }

    // use o(1) extra space, build next level on current level
    Node* connect2(Node* root) {
        if (root == nullptr)
            return root;

        Node *leftmost = root;
        while (leftmost->left != nullptr) {     // still has next level
            Node *cur = leftmost;
            while (cur != nullptr) {
                // same subtree
                cur->left->next = cur->right;

                // cross subtree if exists
                if (cur->next != nullptr)
                    cur->right->next = cur->next->left;

                cur = cur->next;                // go to next node in same level
            }

            leftmost = leftmost->left;          // go to next level
        }

        return root;
    }
};

int main() {
    Solution *s = new Solution();

    Node *n11 = new Node(1);
    Node *n121 = new Node(2); n11->left = n121;
    Node *n122 = new Node(3); n11->right = n122;
    Node *n131 = new Node(4); n121->left = n131;
    Node *n132 = new Node(5); n121->right = n132;
    Node *n133 = new Node(6); n122->left = n133;
    Node *n134 = new Node(7); n122->right = n134;

    s->connect(n11);
}