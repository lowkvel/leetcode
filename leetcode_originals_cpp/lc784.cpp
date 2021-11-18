/*
    784.    字母大小全排列

    给定一个字符串S，通过将字符串S中的每个字母转变大小写，我们可以获得一个新的字符串。返回所有可能得到的字符串集合。

    示例：
        输入：S = "a1b2"
        输出：["a1b2", "a1B2", "A1b2", "A1B2"]

        输入：S = "3z4"
        输出：["3z4", "3Z4"]

        输入：S = "12345"
        输出：["12345"]
    
    提示：
        S 的长度不超过12。
        S 仅由数字和字母组成。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/letter-case-permutation
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    // recursion, backtrack
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        if (s.length() > 0)
            dfs(s, ans, 0);
        return ans;
    }

    void dfs(string s, vector<string> &ans, int index) {
        if (index == s.length()) {      // all characters traversed, add to answer
            ans.push_back(s);
            return;
        }

        if (s[index] >= 'A' && s[index] <= 'Z') {           // we change it, current char within A-Z, + then -
            s[index] = s[index] + ('a' - 'A');
            dfs(s, ans, index + 1);
            s[index] = s[index] - ('a' - 'A');
        } else if (s[index] >= 'a' && s[index] <= 'z') {    // we change it, current char within a-z, - then +
            s[index] = s[index] - ('a' - 'A');
            dfs(s, ans, index + 1);
            s[index] = s[index] + ('a' - 'A');
        } 
            
        dfs(s, ans, index + 1);                             // we dont change any character, just dive in
    }
};

int main() {
    Solution *s = new Solution();
    
    string s1 = "1a2b";
    s->letterCasePermutation(s1);
}
