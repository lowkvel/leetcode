/*
    20. 有效的括号

    给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

    有效字符串需满足：
        左括号必须用相同类型的右括号闭合。
        左括号必须以正确的顺序闭合。
     

    示例 1：
        输入：s = "()"
        输出：true

    示例 2：
        输入：s = "()[]{}"
        输出：true

    示例 3：
        输入：s = "(]"
        输出：false

    示例 4：
        输入：s = "([)]"
        输出：false

    示例 5：
        输入：s = "{[]}"
        输出：true
    
    提示：
        1 <= s.length <= 104
        s 仅由括号 '()[]{}' 组成

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/valid-parentheses
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c: s) 
            if (c == '(' || c == '[' || c == '{')
                stk.push(c);
            else {
                if (stk.empty() ||
                    (c == ')' && stk.top() != '(') ||
                    (c == ']' && stk.top() != '[') ||
                    (c == '}' && stk.top() != '{'))
                        return false;
                else
                    stk.pop();
            }
        return stk.empty();
    }
};

int main() {

}