/*
    复杂链表的复制

    请实现 copyRandomList 函数，复制一个复杂链表。
    在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。

    提示：
        -10000 <= Node.val <= 10000
        Node.random 为空（null）或指向链表中的节点。
        节点数目不超过 1000 。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

# include <iostream>
# include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    // iteration with map
    Node* copyRandomList(Node* head) {
        // deal with empty list
        if (head == nullptr)
            return nullptr;

        // used to store old-new pair
        unordered_map<Node*, Node*> map;

        // copy each node's value into a new node, put it in a map
        Node *curr = head;
        while (curr != nullptr) {
            map[curr] = new Node(curr->val);        // map[original_node] = new node with original node's value
            curr = curr->next;                      // next node
        }

        // copy each node's next/random into the new node stored in the map
        curr = head;
        while (curr != nullptr) {
            map[curr]->next = map[curr->next];      // copy ->next
            map[curr]->random = map[curr->random];  // copy ->random
            curr = curr->next;                      // next node
        }

        // return new head
        return map[head];
    }

    // iteration without map
    Node* copyRandomList2(Node* head) {
        // deal with empty list
        if (head == nullptr)
            return nullptr;

        // copy each node, and insert each new node into the original list, like below
        // old1 -> new1 -> old2 -> new2 -> old3 -> new3 -> ... -> eldn -> newn -> nullptr
        Node *curr = head;
        while (curr != nullptr) {
            Node *temp = new Node(curr->val);   // copy a new node
            temp->next = curr->next;            // direct new node's next to old node's next
            curr->next = temp;                  // direct old node's next to new node itself
            curr = temp->next;                  // next node
        }

        // construct each new node's random direction
        curr = head;
        while (curr != nullptr) {
            if (curr->random != nullptr)                    // this node must be a old node
                curr->next->random = curr->random->next;    // the random direction of this old node's next node = the next node of this old node's random node
            curr = curr->next->next;                        // next of next node must be a old node
        }

        // separate two linked list
        curr = head->next;                      // the first new node
        Node *prev = head;                      // old linked list
        Node *rest = head->next;                // new linked list
        while (curr->next != nullptr) {         // still have new node after this old node
            prev->next = prev->next->next;      // skip new node
            curr->next = curr->next->next;      // skip old node
            prev = prev->next;                  // move to next new node
            curr = curr->next;                  // move to next old node
        }
        prev->next = nullptr;                   // deal with old linkded list's last nullptr
        return rest;                            // return the head of new linked list
    }
};

int main() {
    Solution *s = new Solution();

}
