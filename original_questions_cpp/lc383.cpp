/*
    赎金信

    给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串 ransom 能不能由第二个字符串 magazines 里面的字符构成。
    如果可以构成，返回 true ；否则返回 false。

    (题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。杂志字符串中的每个字符只能在赎金信字符串中使用一次。)

    示例 1：
        输入：ransomNote = "a", magazine = "b"
        输出：false

    示例 2：
        输入：ransomNote = "aa", magazine = "ab"
        输出：false

    示例 3：
        输入：ransomNote = "aa", magazine = "aab"
        输出：true
     
    提示：
        你可以假设两个字符串均只含有小写字母。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/ransom-note
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <unordered_map>

using namespace std;

class Solution {
public:
    // map
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> umap;
        
        for (char c: magazine)
            if (umap.count(c) == 0)
                umap[c] = 1;
            else
                umap[c]++;

        for (char c: ransomNote)
            if (umap.count(c) == 0 || umap[c] <= 0)
                return false;
            else
                umap[c]--;

        return true;
    }

    // replace
    bool canConstruct2(string ransomNote, string magazine) {
        for (char c: ransomNote)
            if (magazine.find(c) != -1)             // found one, replace it with irrelavent char '.'
                magazine[magazine.find(c)] = '.';
            else                                    // none found, return false
                return false;   
        return true;
    }
};

int main() {
    Solution *s  = new Solution();

    string s1 = "a";
    string s2 = "b";
    printf("%d\n", s->canConstruct2(s1, s2));

    string s3 = "aa";
    string s4 = "ab";
    printf("%d\n", s->canConstruct2(s3, s4));

    string s5 = "aa";
    string s6 = "aab";
    printf("%d\n", s->canConstruct2(s5, s6));
}