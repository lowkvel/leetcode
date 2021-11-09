/*
    无重复字符的最长子串

    给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

    示例 1:
        输入: s = "abcabcbb"
        输出: 3 
        解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

    示例 2:
        输入: s = "bbbbb"
        输出: 1
        解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

    示例 3:
        输入: s = "pwwkew"
        输出: 3
        解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
             请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

    示例 4:
        输入: s = ""
        输出: 0

    提示：
        0 <= s.length <= 5 * 104
        s 由英文字母、数字、符号和空格组成

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <unordered_set>

using namespace std;

class Solution {
public:
    /*
        方法一：滑动窗口

        思路和算法

        我们先用一个例子考虑如何在较优的时间复杂度内通过本题。

        我们不妨以示例一中的字符串 abcabcbb 为例，找出从每一个字符开始的，不包含重复字符的最长子串，那么其中最长的那个字符串即为答案。

        对于示例一中的字符串，我们列举出这些结果，其中括号中表示选中的字符以及最长的字符串：
            以 (a)bcabcbb 开始的最长字符串为 (abc)abcbb；
            以 a(b)cabcbb 开始的最长字符串为 a(bca)bcbb；
            以 ab(c)abcbb 开始的最长字符串为 ab(cab)cbb；
            以 abc(a)bcbb 开始的最长字符串为 abc(abc)bb；
            以 abca(b)cbb 开始的最长字符串为 abca(bc)bb；
            以 abcab(c)bb 开始的最长字符串为 abcab(cb)b；
            以 abcabc(b)b 开始的最长字符串为 abcabc(b)b；
            以 abcabcb(b) 开始的最长字符串为 abcabcb(b)。
        如果我们依次递增地枚举子串的起始位置，那么子串的结束位置也是递增的！

        *****
        这里的原因在于，假设我们选择字符串中的第 k 个字符作为起始位置，并且得到了不包含重复字符的最长子串的结束位置为 r ，​
        那么当我们选择第 k+1 个字符作为起始位置时，首先从 k+1 到 r 的字符显然是不重复的，
        并且由于少了原本的第 k 个字符，我们可以尝试继续增大 r ，直到右侧出现了重复字符为止。
        *****

        这样一来，我们就可以使用「滑动窗口」来解决这个问题了：
        我们使用两个指针表示字符串中的某个子串（或窗口）的左右边界，其中左指针代表着上文中「枚举子串的起始位置」，而右指针即为上文中的 r ,
        在每一步的操作中，我们会将左指针向右移动一格，表示 我们开始枚举下一个字符作为起始位置，
        然后我们可以不断地向右移动右指针，但需要保证这两个指针对应的子串中没有重复的字符。
        在移动结束后，这个子串就对应着 以左指针开始的，不包含重复字符的最长子串。我们记录下这个子串的长度；
        在枚举结束后，我们找到的最长的子串的长度即为答案。

        作者：LeetCode-Solution
        链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-by-leetc-2/
        来源：力扣（LeetCode）
        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    */
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> uset;
        int right = -1;                             // right initialized to -1
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (i != 0)
                uset.erase(s[i - 1]);               // remove previous char from set

            while (right + 1 < s.size()             // size ok
                    && !uset.count(s[right + 1])) { // char not in set
                uset.insert(s[right + 1]);          // insert into set
                ++right;                            // move right forward
            }

            ans = max(ans, right - i + 1);
        }

        return ans;
    }
};

int main() {
    Solution *s  = new Solution();

    string s1 = "abcabcbb";
    printf("%d\n", s->lengthOfLongestSubstring(s1));

    string s2 = "bbbbb";
    printf("%d\n", s->lengthOfLongestSubstring(s2));

    string s3 = "pwwkew";
    printf("%d\n", s->lengthOfLongestSubstring(s3));

    string s4 = "";
    printf("%d\n", s->lengthOfLongestSubstring(s4));
}