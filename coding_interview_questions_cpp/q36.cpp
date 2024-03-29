/*
    36. 二叉搜索树与双向链表

    输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。
    要求不能创建任何新的节点，只能调整树中节点指针的指向。

    为了让您更好地理解问题，以下面的二叉搜索树为例：
        4
       / \
      2  5
     / \
    1  3

    我们希望将这个二叉搜索树转化为双向循环链表。
    链表中的每个节点都有一个前驱和后继指针。
    对于双向循环链表，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。

    下图展示了上面的二叉搜索树转化成的链表。
    “head” 表示指向链表中有最小元素的节点。

    head -> 1 <-> 2 <-> 3 <-> 4 <-> 5
            ^-----------------------^

    特别地，我们希望可以就地完成转换操作。
    当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。
    还需要返回链表中的第一个节点的指针。

    注意：本题与主站 426 题相同：https://leetcode-cn.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/
    注意：此题对比原题有改动。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

# include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node *prev = nullptr;
    Node *head = nullptr;
    
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr)
            return nullptr;

        inorder_dfs(root);
        head->left = prev;          // build head->left to prev (points to last node after inorder_bfs)
        prev->right = head;         // build prev->right to head

        return head;
    }

    void inorder_dfs(Node *node) {
        if (node == nullptr)        // out of bound
            return;

        inorder_dfs(node->left);    // diving in, left
        if (prev == nullptr)        // accessing the smallest node (the hasnt been initialized yet), the head
            head = node;            // initialize head
        else                        // accessing nodes after the smallest node
            prev->right = node;     // build prev->right to current_node
        node->left = prev;          // build current_node->left to prev
        prev = node;                // move prev points to current node for next round
        inorder_dfs(node->right);   // diving in, right
    }
};

int main() {
    Solution *s = new Solution();

    Node *n1 = new Node(4);
    Node *n2 = new Node(2); n1->left = n2;
    Node *n3 = new Node(5); n1->right = n3;
    Node *n4 = new Node(1); n2->left = n4;
    Node *n5 = new Node(3); n2->right = n5;

    s->treeToDoublyList(n1);
}