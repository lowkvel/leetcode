/*
    21. 合并两个有序链表

    将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

    示例 1：
        输入：l1 = [1,2,4], l2 = [1,3,4]
        输出：[1,1,2,3,4,4]

    示例 2：
        输入：l1 = [], l2 = []
        输出：[]

    示例 3：
        输入：l1 = [], l2 = [0]
        输出：[0]
    
    提示：
        两个链表的节点数目范围是 [0, 50]
        -100 <= Node.val <= 100
        l1 和 l2 均按 非递减顺序 排列
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

    // recursion
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;
        else if (l2 == nullptr)
            return l1;
        else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }

    // cursor
    ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {

        ListNode *ans = new ListNode(-1);           // lead node
        ListNode *cur = ans;                        // track merged front

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {                // redirect to l1
                cur->next = l1;
                l1 = l1->next;
            } else {                                // redirect to l2
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;                        // move front forward
        }

        l1 == nullptr ? cur->next = l2 : cur->next = l1;    // redirect to list not merged

        return ans->next;
    }
};

int main() {

}