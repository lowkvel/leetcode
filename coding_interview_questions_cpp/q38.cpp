/*
    38. 字符串的排列

    输入一个字符串，打印出该字符串中字符的所有排列。

    你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

    示例:
        输入：s = "abc"
        输出：["abc","acb","bac","bca","cab","cba"]
     
    限制：
        1 <= s 的长度 <= 8

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>
# include <set>

using namespace std;

class Solution {
public:
    vector<string> ans;

    vector<string> permutation(string s) {
        dfs(s, 0);
        return ans;
    }

    void dfs(string s, int x) {
        if (x == s.size() - 1) {
            ans.push_back(s);
            return;
        }

        set<int> st;
        for (int i = x; i < s.size(); i++) {
            if (st.find(s[i]) != st.end())      // duplication found, skip this char
                continue;
            st.insert(s[i]);                    // insert the choosed char (index >= x) into set for duplication checking
            swap(s[i], s[x]);                   // put the selected char (index >= x) on current position at index x
            dfs(s, x + 1);                      // dive in
            swap(s[i], s[x]);                   // swap back
        }
    }
};

int main() {

}