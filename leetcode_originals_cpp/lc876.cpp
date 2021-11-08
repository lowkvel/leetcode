/*
    876. 链表的中间节点

    给定一个头结点为 head 的非空单链表，返回链表的中间结点。
    如果有两个中间结点，则返回第二个中间结点。

    示例 1：
        输入：[1,2,3,4,5]
        输出：此列表中的结点 3 (序列化形式：[3,4,5])
        返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
        注意，我们返回了一个 ListNode 类型的对象 ans，这样：
        ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.

    示例 2：
        输入：[1,2,3,4,5,6]
        输出：此列表中的结点 4 (序列化形式：[4,5,6])
        由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。
    
    提示：
        给定链表的结点数介于 1 和 100 之间。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/middle-of-the-linked-list
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

# include <iostream>
# include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode *> v;
        ListNode *cur = head;
        while (cur != nullptr) {
            v.push_back(cur);
            cur = cur->next;
        }
        return v[v.size() / 2];
    }

    // single pointer, traverse twice
    ListNode* middleNode2(ListNode* head) {
        int nodeCount = 0;
        ListNode *cursor = head;
        while (cursor != nullptr) {
            ++nodeCount;
            cursor = cursor->next;
        }

        int halfCount = 0;
        cursor = head;
        while (halfCount < nodeCount / 2) {
            ++halfCount;
            cursor = cursor->next;
        }

        return cursor;
    }

    // slow & fast pointers
    ListNode* middleNode3(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

int main() {

}