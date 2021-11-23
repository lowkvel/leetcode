/*
    左旋转字符串

    字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
    请定义一个函数实现字符串左旋转操作的功能。
    比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

    示例 1：
        输入: s = "abcdefg", k = 2
        输出: "cdefgab"

    示例 2：
        输入: s = "lrloseumgh", k = 6
        输出: "umghlrlose"
     
    限制：
        1 <= k < s.length <= 10000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>

using namespace std;

class Solution {
public:
    // use additional string
    string reverseLeftWords(string s, int n) {
        string ans = "";
        int len = s.size();
        n = n % s.size();

        for (int i = 0; i < len; i++)
            ans.push_back(s[(n + i) % len]);

        return ans;
    }

    // ring-like substitution, math
    string reverseLeftWords2(string s, int n) {

        return "";
    }

    // triple reverse
    string reverseLeftWords3(string s, int n) {
        n = n % s.size();
        char temp;

        // whole string reverse
        int head = 0;
        int tail = s.size() - 1;
        while (head < tail) {
            temp = s[head];
            s[head] = s[tail];
            s[tail] = temp;
            head++;
            tail--;
        }

        // [0, s.size() - n - 1] reverse
        head = 0;
        tail = s.size() - n - 1;
        while (head < tail) {
            temp = s[head];
            s[head] = s[tail];
            s[tail] = temp;
            head++;
            tail--;
        }

        // [s.size() - n, s.size() - 1] reverse
        head = s.size() - n;
        tail = s.size() - 1;
        while (head < tail) {
            temp = s[head];
            s[head] = s[tail];
            s[tail] = temp;
            head++;
            tail--;
        }

        return s;
    }
};

int main() {
    Solution *s = new Solution();

    string s1 = "abcdefg";
    printf("%s\n", s->reverseLeftWords(s1, 9).c_str());
    printf("%s\n", s->reverseLeftWords3(s1, 9).c_str());
}
