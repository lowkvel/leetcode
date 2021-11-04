/*
    反转链表
    
    定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

    示例:
        输入: 1->2->3->4->5->NULL
        输出: 5->4->3->2->1->NULL 

    限制：
        0 <= 节点个数 <= 5000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

# include <iostream>
# include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;

        while (curr != NULL) {
            ListNode *next = curr->next;    // pre-store next node for moving prev/curr pair
            curr->next = prev;              // reverse link
            prev = curr;                    // move prev to curr
            curr = next;                    // move curr to pre-stored next
        }

        return prev;
    }

    ListNode* reverseList2(ListNode* head) {
        return recursion(head, nullptr);
    }

    ListNode* recursion(ListNode *curr, ListNode *prev) {
        if (curr == nullptr)                                // end of recursion
            return prev;

        ListNode *next = recursion(curr->next, curr);       // recursion(next, curr)

        curr->next = prev;                                  // reverse link

        return next;                                        // return head
    }
};

int main() {
    Solution *s = new Solution();

}
