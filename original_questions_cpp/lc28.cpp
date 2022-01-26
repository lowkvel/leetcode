/*
    28. 实现strStr()

    实现 strStr() 函数。
    给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。
    如果不存在，则返回  -1 。

    说明：
        当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
        对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf() 定义相符。

    示例 1：
        输入：haystack = "hello", needle = "ll"
        输出：2

    示例 2：
        输入：haystack = "aaaaa", needle = "bba"
        输出：-1

    示例 3：
        输入：haystack = "", needle = ""
        输出：0
    
    提示：
        0 <= haystack.length, needle.length <= 5 * 10^4
        haystack 和 needle 仅由小写英文字符组成

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/implement-strstr
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>

using namespace std;

class Solution {
public:
    // brute force
    int strStr(string haystack, string needle) {
        if (needle == "")
            return 0;

        int n = haystack.size();
        int m = needle.size();

        for (int i = 0; i + m <= n; i++) {
            bool flag = true;
            for (int j = 0; j < m; j++) 
                if (haystack[i + j] != needle[j]) {
                    flag = false;
                    break;
                }
            if (flag)
                return i;
        }

        return -1;
    }

    // Knuth-Morris-Pratt, kmp
    // TODO
    int strStr(string haystack, string needle) {

    }
};

int main() {
    Solution *s = new Solution();

}