/*
    139. 单词拆分

    给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。
    注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

    示例 1：
        输入: s = "leetcode", wordDict = ["leet", "code"]
        输出: true
        解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。

    示例 2：
        输入: s = "applepenapple", wordDict = ["apple", "pen"]
        输出: true
        解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
             注意，你可以重复使用字典中的单词。

    示例 3：
        输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
        输出: false
     
    提示：
        1 <= s.length <= 300
        1 <= wordDict.length <= 1000
        1 <= wordDict[i].length <= 20
        s 和 wordDict[i] 仅有小写英文字母组成
        wordDict 中的所有字符串 互不相同

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/word-break
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>
# include <unordered_set>

using namespace std;

class Solution {
public:
    // dp
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> uset;                                 // use set as dict for fast retrival
        for (string s: wordDict)
            uset.insert(s);

        vector<bool> dp(s.size() + 1, false);                       // dp, dp[i] is true means s[0:i) can be cut using strings in dict
        dp[0] = true;                                               // empty string is true
        for (int i = 0; i < s.size(); i++)                          // start from each char at index i
            for (int j = i + 1; j < s.size() + 1; j++)              // end with char at index j, gives s[i:j)
                if (dp[i] && uset.count(s.substr(i, j - i)) > 0)    // check for dp[0:i] is true and s[i:j) is in dict
                    dp[j] = true;

        return dp[s.size()];
    }
};

int main() {
    Solution *sol = new Solution();

    string s1 = "leetcode";
    vector<string> v1;
    v1.push_back("leet");
    v1.push_back("code");
    cout << sol->wordBreak(s1, v1) << endl;

    string s2 = "applepenapple";
    vector<string> v2;
    v2.push_back("apple");
    v2.push_back("pen");
    cout << sol->wordBreak(s2, v2) << endl;

    string s3 = "catsandog";
    vector<string> v3;
    v3.push_back("cats");
    v3.push_back("dog");
    v3.push_back("sand");
    v3.push_back("and");
    v3.push_back("cat");
    cout << sol->wordBreak(s3, v3) << endl;
}