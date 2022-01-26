/*
    14. 最长公共前缀

    编写一个函数来查找字符串数组中的最长公共前缀。
    如果不存在公共前缀，返回空字符串 ""。

    示例 1：
        输入：strs = ["flower","flow","flight"]
        输出："fl"

    示例 2：
        输入：strs = ["dog","racecar","car"]
        输出：""
        解释：输入不存在公共前缀。
    
    提示：
        1 <= strs.length <= 200
        0 <= strs[i].length <= 200
        strs[i] 仅由小写英文字母组成

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/longest-common-prefix
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    // vertical scan
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() <= 0)
            return "";
        if (strs.size() == 1)
            return strs[0];
        
        int maxLength = strs[0].length();
        for (int i = 0; i < strs.size(); i++)
            if (strs[i].length() < maxLength)
                maxLength = strs[i].length();

        int index = 0;
        while (index < maxLength) {
            for (int i = 0; i < strs.size() - 1; i++)
                if (strs[i][index] != strs[i + 1][index])
                    return strs[0].substr(0, index);
            index++;
        }

        return strs[0].substr(0, index); 
    }

    // horizontal scan
    string longestCommonPrefix2(vector<string>& strs) {
        if (strs.size() <= 0)
            return "";
        if (strs.size() == 1)
            return strs[0];

        string ans = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            ans = ans.substr(0, min(ans.length(), strs[i].length()));       // shortern the ans if needed
            for (int j = 0; j < min(ans.length(), strs[i].length()); j++) 
                if (ans[j] != strs[i][j]) {
                    ans = ans.substr(0, j);
                    break;
                }
            if (ans == "")                                                  // early quits
                return ans;
        }

        return ans;
    }
};

int main() {
    Solution *s = new Solution();
    
    vector<string> v1;
    v1.push_back("ab");
    v1.push_back("a");

    s->longestCommonPrefix2(v1);
}