/*
    9. 删除链表的倒数第n个节点

    给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

    示例 1：
        输入：head = [1,2,3,4,5], n = 2
        输出：[1,2,3,5]

    示例 2：
        输入：head = [1], n = 1
        输出：[]

    示例 3：
        输入：head = [1,2], n = 1
        输出：[1]
     
    提示：
        链表中结点的数目为 sz
        1 <= sz <= 30
        0 <= Node.val <= 100
        1 <= n <= sz

    进阶：你能尝试使用一趟扫描实现吗？

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
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
# include <stack>

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
        在对链表进行操作时，一种常用的技巧是添加一个哑节点（dummy node），它的 next 指针指向链表的头节点。
        这样一来，我们就不需要对头节点进行特殊的判断了。
        */
        ListNode *priorHead = new ListNode(-1, head);   // add a node prior to head

        ListNode *cur = head;                           // count length
        int length = 0;
        while (cur != nullptr) {
            ++length;
            cur = cur->next;
        }
        if (n > length)                                 // deal with exceptions
            return head;

        cur = priorHead;                                // move to the node prior to the node to be deleted
        for (int i = 0; i < length - n; i++) 
            cur = cur->next;
        
        ListNode *temp = cur->next;                     // delete the target node
        cur->next = cur->next->next;
        delete temp;
        
        ListNode *ans = priorHead->next;                // construct answer
        delete priorHead;

        return ans;                                     // return it
    }

    // stack
    ListNode* removeNthFromEnd2(ListNode* head, int n) {
        /*
        在对链表进行操作时，一种常用的技巧是添加一个哑节点（dummy node），它的 next 指针指向链表的头节点。
        这样一来，我们就不需要对头节点进行特殊的判断了。
        */
        ListNode *priorHead = new ListNode(-1, head);   // add a node prior to head
        stack<ListNode *> s;

        ListNode *cur = priorHead;
        while (cur != nullptr) {
            s.push(cur);
            cur = cur->next;
        }

        for (int i = 0; i < n; i++)
            s.pop();

        ListNode *temp = s.top()->next;
        s.top()->next = s.top()->next->next;
        delete temp;

        ListNode *ans = priorHead->next;
        delete priorHead;
        return ans;
    }

    // slow & fast
    ListNode* removeNthFromEnd3(ListNode* head, int n) {
        /*
        在对链表进行操作时，一种常用的技巧是添加一个哑节点（dummy node），它的 next 指针指向链表的头节点。
        这样一来，我们就不需要对头节点进行特殊的判断了。
        */
        ListNode *priorHead = new ListNode(-1, head);   // add a node prior to head

        ListNode *slow = priorHead;
        ListNode *fast = head;

        for (int i = 0; i < n; i++)
            fast = fast->next;

        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        ListNode *ans = priorHead->next;
        delete priorHead;
        return ans;
    }
};

int main () {
    Solution *s = new Solution();

    ListNode * n0 = new ListNode(1); 
    ListNode * n1 = new ListNode(2); 
    ListNode * n2 = new ListNode(3); 
    ListNode * n3 = new ListNode(4); 
    ListNode * n4 = new ListNode(5); 
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    s->removeNthFromEnd2(n0, 2);
}