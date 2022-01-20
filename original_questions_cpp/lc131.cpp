/*
    131. 分割回文串

    给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
    回文串 是正着读和反着读都一样的字符串。

    示例 1：
        输入：s = "aab"
        输出：[["a","a","b"],["aa","b"]]

    示例 2：
        输入：s = "a"
        输出：[["a"]]
     
    提示：
        1 <= s.length <= 16
        s 仅由小写英文字母组成

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/palindrome-partitioning
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> f;
    vector<vector<string>> anst;
    vector<string> ans;
    int ssize;

public:
    // dp (pre-calculate palindrome) + backtrack
    vector<vector<string>> partition(string s) {
        ssize = s.size();

        // dp, pre-determine substring sets are palindrome or not
        f.assign(ssize, vector<int>(ssize, true));
        for (int i = ssize - 1; i >= 0; --i)                    // from right
            for (int j = i + 1; j < ssize; ++j)                 // from left
                f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];    // f[i][j] is palindrome only if (s[i]==s[j] && f[i+1][j-1] is palindrome)

        dfs(s, 0);
        return anst;
    }

    // dfs + backtrack
    void dfs(const string &s, int i) {                          // (string, starting point i), assuming [0, i-1] is cut
        if (i == ssize) {                                       // end of string reached
            anst.push_back(ans);                                // add answer into answer_total
            return;
        }

        for (int j = i; j < ssize; ++j)                         // loop through [i, ssize-1]
            if (f[i][j]) {                                      // if s[i] to s[j] is palindrome
                ans.push_back(s.substr(i, j - i + 1));          // add to answer
                dfs(s, j + 1);                                  // dive in (starting from j+1 ([i, j] is added to answer))
                ans.pop_back();                                 // backtrack
            }
    }
};

int main() {
    Solution *s = new Solution();

    string s1 = "aab";
    string s2 = "aaba";
    string s3 = "a";

    s->partition(s2);
}