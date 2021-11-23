/*
    25. 合并两个排序的链表

    输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

    示例1：

        输入：1->2->4, 1->3->4
        输出：1->1->2->3->4->4

    限制：
        0 <= 链表长度 <= 1000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof
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

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *preHead = new ListNode(-1);
        ListNode *cur = preHead;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }

            // cur trasverse on l1 and l2, change each node->next to proper node (could be on the other list)
            cur = cur->next;    
        }

        // merging the remaining nodes
        if (l1 == nullptr)
            cur->next = l2;
        else
            cur->next = l1;

        return preHead->next;
    }
};

int main() {

}