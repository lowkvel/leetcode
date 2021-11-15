/*
    52. 两个链表的第一个公共节点

    输入两个链表，找出它们的第一个公共节点。

    如下面的两个链表：
                a1  ->  b1 \
                            >   c1 ->   c2 ->   c3
        b1  ->  b2  ->  b3 /
    在节点 c1 开始相交。

    示例 1：
                4 ->    1 \
                            >   8 ->    4 ->    5
        5 ->    0 ->    1 /
        输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
        输出：Reference of the node with value = 8
        输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
         
    示例 2：
        0 ->    9 ->    1 \
                            >   2 ->    4
                        3 /
        输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
        输出：Reference of the node with value = 2
        输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
         
    示例 3：
        2 ->    6 ->    4
                1 ->    5
        输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
        输出：null
        输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
        解释：这两个链表不相交，因此返回 null。
         
    注意：
        如果两个链表没有交点，返回 null.
        在返回结果后，两个链表仍须保持原有的结构。
        可假定整个链表结构中没有循环。
        程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
        本题与主站 160 题相同：https://leetcode-cn.com/problems/intersection-of-two-linked-lists/

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof
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
# include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // set
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> uset;

        ListNode *temp = headA;
        while (temp != nullptr) {
            uset.insert(temp);
            temp = temp->next;
        }

        temp = headB;
        while (headB != nullptr)
            if (uset.count(headB) > 0)
                return headB;
            else
                headB = headB->next;

        return nullptr;
    }

    // dual pointers
    /*
        使用双指针的方法，可以将空间复杂度降至 O(1)。

        只有当链表 headA 和 headB 都不为空时，两个链表才可能相交。
        因此首先判断链表 headA 和 headB 是否为空，如果其中至少有一个链表为空，则两个链表一定不相交，返回 null。
        当链表 headA 和 headB 都不为空时，创建两个指针 pA 和 pB，初始时分别指向两个链表的头节点 headA 和 headB，然后将两个指针依次遍历两个链表的每个节点。
        
        具体做法如下：
            每步操作需要同时更新指针 pA 和 pB。
            如果指针 pA 不为空，则将指针 pA 移到下一个节点；如果指针 pB 不为空，则将指针 pB 移到下一个节点。
            如果指针 pA 为空，则将指针 pA 移到链表 headB 的头节点；如果指针 pB 为空，则将指针 pB 移到链表 headA 的头节点。
            当指针 pA 和 pB 指向同一个节点或者都为空时，返回它们指向的节点或者 null。

        证明
            下面提供双指针方法的正确性证明。考虑两种情况，第一种情况是两个链表相交，第二种情况是两个链表不相交。
                情况一：两个链表相交

                    链表 headA 和 headB 的长度分别是 m 和 n。
                    假设链表 headA 的不相交部分有 a 个节点，链表 headB 的不相交部分有 b 个节点，两个链表相交的部分有 c 个节点，则有 a + c = m，b + c = n。
                    如果 a = b，则两个指针会同时到达两个链表的第一个公共节点，此时返回两个链表的第一个公共节点；
                    如果 a != b，则指针 pA 会遍历完链表 headA，指针 pB 会遍历完链表 headB，两个指针不会同时到达链表的尾节点，
                        然后指针 pA 移到链表 headB 的头节点，指针 pB 移到链表 headA 的头节点，然后两个指针继续移动，
                        在指针 pA 移动了 a + c + b 次、指针 pB 移动了 b + c + a 次之后，
                        两个指针会同时到达两个链表的第一个公共节点，该节点也是两个指针第一次同时指向的节点，此时返回两个链表的第一个公共节点。
                情况二：两个链表不相交
                    链表 headA 和 headB 的长度分别是 m 和 n。考虑当 m = n 和 m != n 时，两个指针分别会如何移动：
                    如果 m = n，则两个指针会同时到达两个链表的尾节点，然后同时变成空值 null，此时返回 null；
                    如果 m != n，则由于两个链表没有公共节点，两个指针也不会同时到达两个链表的尾节点，因此两个指针都会遍历完两个链表，
                    在指针 pA 移动了 m + n 次、指针 pB 移动了 n + m 次之后，两个指针会同时变成空值 null，此时返回 null。

        作者：LeetCode-Solution
        链接：https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/solution/liang-ge-lian-biao-de-di-yi-ge-gong-gong-pzbs/
        来源：力扣（LeetCode）
        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    */
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;

        ListNode *cura = headA;
        ListNode *curb = headB;

        while (cura != curb) {
            cura == nullptr ? cura = headB : cura = cura->next;
            curb == nullptr ? curb = headA : curb = curb->next;
        }

        return cura;
    }
};

int main() {

}

