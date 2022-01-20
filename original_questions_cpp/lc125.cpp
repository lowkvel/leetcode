/*
    125. 验证回文串

    给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
    说明：本题中，我们将空字符串定义为有效的回文串。

    示例 1:
        输入: "A man, a plan, a canal: Panama"
        输出: true
        解释："amanaplanacanalpanama" 是回文串

    示例 2:
        输入: "race a car"
        输出: false
        解释："raceacar" 不是回文串
    
    提示：
        1 <= s.length <= 2 * 10^5
        字符串 s 由 ASCII 字符组成

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/valid-palindrome
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>

using namespace std;

class Solution {
public:
    // dual pointers
    bool isPalindrome(string s) {
        if (s == "")
            return true;

        int i = 0;
        int j = s.length() - 1;
        while (i <= j) {
            while (i <= j && !isValid(s[i]))    // skipping invalid characters from left
                i++;
            while (i <= j && !isValid(s[j]))    // skipping invalid characters from right
                j--;

            if (i > j)                          // no valid character left, matched
                break;
            else {
                if (transform(s[i]) != transform(s[j]))     // not matching, return
                    return false;
                else {                                      // matched, move forward
                    i++;
                    j--;
                }
            }
        }

        return true;
    }

    bool isValid(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }

    char transform(char c) {
        if (c >= 'A' && c <= 'Z')
            return c + ('a' - 'A');
        return c;
    }
};

int main() {
    Solution *s = new Solution();

    string s1 = "A man, a plan, a canal: Panama";
    cout << s->isPalindrome(s1) << endl;

    string s2 = "race a car";
    cout << s->isPalindrome(s2) << endl;

    //cout << 'D' - 'a' + 'A' << endl;
    //cout << 'D' << endl;
}