/*
    从尾到头打印链表
    
    输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

    示例 1：
        输入：head = [1,3,2]
        输出：[2,3,1]
 
    限制：
        0 <= 链表长度 <= 10000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof
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
# include <vector>
# include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    // stack
    vector<int> reversePrint(ListNode* head) {
        stack<int> s;
        while (head != NULL) {
            s.push(head->val);
            head = head->next;
        }

        vector<int> v;
        while (!s.empty()) {
            v.push_back(s.top());
            s.pop();
        }

        return v;
    }

    // recursion
    vector<int> reversePrint2(ListNode* head) {
        if (head == NULL)
            return {};

        vector<int> v = reversePrint2(head->next);

        v.push_back(head->val);
        
        return v;
    }
};

int main() {
    Solution *s = new Solution();


}
