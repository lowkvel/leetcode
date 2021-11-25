/*
    33. 二叉搜索树的后续遍历序列

    输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。

    参考以下这颗二叉搜索树：
        5
       / \
      2   6
     / \
    1   3

    示例 1：
        输入: [1,6,3,2,5]
        输出: false

    示例 2：
        输入: [1,3,2,6,5]
        输出: true
    
    提示：
        数组长度 <= 1000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>
# include <stack>

using namespace std;

class Solution {
public:
    // recursion, division
    bool verifyPostorder(vector<int>& postorder) {
        return recursion(postorder, 0, postorder.size() - 1);
    }

    bool recursion(vector<int> &po, int left, int right) {
        if (left >= right)                          // node count less than 0, return true
            return true;

        int p = left;
        while (po[p] < po[right])                   // find the first element greater than root (right most node) for left subtree
            p++;
        int m = p;                                  // then mark its position as m

        while (po[p] > po[right])                   // check if all elements starting from m is greater than root (right most node) for right subtree
            p++;

        return  p == right &&                       // all elements starting from m is greater than root
                recursion(po, left, m - 1) &&       // recursively check left subtree [left, m - 1]
                recursion(po, m, right - 1);        // recursively check right subtree [m, right - 1]
    }

    // stack
    bool verifyPostorder2(vector<int>& postorder) {
        stack<int> s;
        int root = INT_MAX;
        for (int i = postorder.size() - 1; i >= 0; i--) {
            if (postorder[i] > root)
                return false;
            while (!s.empty() && s.top() > postorder[i]) {
                root = s.top();
                s.pop();
            }
            s.push(postorder[i]);
        }
        return true;
    }
};

int main() {

}