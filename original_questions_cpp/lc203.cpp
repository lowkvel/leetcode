/*
    203. 移除链表元素

    给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 
    示例 1：
        输入：head = [1,2,6,3,4,5,6], val = 6
        输出：[1,2,3,4,5]

    示例 2：
        输入：head = [], val = 1
        输出：[]

    示例 3：
        输入：head = [7,7,7,7], val = 7
        输出：[]
     
    提示：
        列表中的节点数目在范围 [0, 104] 内
        1 <= Node.val <= 50
        0 <= val <= 50

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/remove-linked-list-elements
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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
            return head;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }

    // cursor
    ListNode* removeElements2(ListNode* head, int val) { 
        ListNode *ans = new ListNode(-1, head);
        ListNode *cur = ans;
        while (cur->next != nullptr) 
            if (cur->next->val == val) {
                ListNode *temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            } else
                cur = cur->next;

        return ans->next;
    }
};

int main() {
    Solution *s = new Solution();

    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(1); n1->next = n2;
    ListNode *n3 = new ListNode(1); n2->next = n3;
    ListNode *n4 = new ListNode(1); n3->next = n4;
    //ListNode *n5 = new ListNode(1); n4->next = n5;
    //ListNode *n6 = new ListNode(1); n5->next = n6;
    //ListNode *n7 = new ListNode(1); n6->next = n7;

    s->removeElements(n1, 1);
}