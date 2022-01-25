/*
    有效的字母异位词

    给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
    注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

    示例 1:
        输入: s = "anagram", t = "nagaram"
        输出: true

    示例 2:
        输入: s = "rat", t = "car"
        输出: false
    
    提示:
        1 <= s.length, t.length <= 5 * 104
        s 和 t 仅包含小写字母
    
    进阶: 
        如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/valid-anagram
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <unordered_map>

using namespace std;

class Solution {
public:
    // sort
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }

    // hash
    bool isAnagram2(string s, string t) {
        if (s.length() != t.length())       // string length different, false
            return false;

        unordered_map<char, int> umap;
        for (char c: s)
            umap[c]++;

        for (char c: t) 
            if (umap.count(c) == 0)         // unseen char met, false
                return false;
            else {
                umap[c]--;
                if (umap[c] < 0)            // char count different, false
                    return false;
            }

        return true;
    }
};

int main() {
    Solution *s  = new Solution();

    string s1 = "anagram";
    string s2 = "nagaram";
    printf("%d\n", s->isAnagram2(s1, s2));

    string s3 = "rat";
    string s4 = "car";
    printf("%d\n", s->isAnagram2(s3, s4));
}