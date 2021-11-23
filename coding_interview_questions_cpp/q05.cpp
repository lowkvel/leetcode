/*
    替换空格

    请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

    示例 1：
        输入：s = "We are happy."
        输出："We%20are%20happy."
 
    限制:
        0 <= s 的长度 <= 10000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string ans;
        
        // for (int i = 0; i < s.size(); i++)
        //     if (s[i] == ' ') 
        //         ans = ans + "%20";
        //     else 
        //         ans = ans + s[i];

        for (auto &c : s)
            if (c == ' ') {
                ans.push_back('%');
                ans.push_back('2');
                ans.push_back('0');
            } else
                ans.push_back(c);

        return ans;
    }

    string replaceSpace2(string s) {
        // count spaces in old string
        int spaceCount = 0;
        for (char c : s) 
            if (c == ' ')
                spaceCount++;

        // record old size, expand string size and record new size
        int oldSize = s.size();
        s.resize(oldSize + spaceCount * 2);
        int newSize = s.size();

        // replace spaces backwards
        for (int i = oldSize - 1, j = newSize - 1; i < j; i--, j--)
            if (s[i] != ' ')        // not space, simple copy
                s[j] = s[i];
            else {                  // space, replace
                s[j - 2] = '%';
                s[j - 1] = '2';
                s[j] = '0';
                j = j - 2;
            }

        // return
        return s;
    }
};

int main() {
    Solution *s = new Solution();

    string s1 = "We are happy.";
    printf("%s\n", s->replaceSpace(s1).c_str());
}
