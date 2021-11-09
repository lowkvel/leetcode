/*
    字符串的排列

    给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列。如果是，返回 true ；否则，返回 false 。

    换句话说，s1 的排列之一是 s2 的 子串 。

    示例 1：
        输入：s1 = "ab" s2 = "eidbaooo"
        输出：true
        解释：s2 包含 s1 的排列之一 ("ba").

    示例 2：
        输入：s1= "ab" s2 = "eidboaoo"
        输出：false
    
    提示：
        1 <= s1.length, s2.length <= 104
        s1 和 s2 仅包含小写字母

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/permutation-in-string
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if (n > m)
            return false;

        // initialize umap1
        unordered_map<char, int> umap1;
        for (int i = 0; i < n; i++)
            if (umap1.count(s1[i]) == 0)
                umap1[s1[i]] = 1;
            else
                umap1[s1[i]]++;

        // initialize umap2
        unordered_map<char, int> umap2;
        for (int i = 0; i < n; i++)
            if (umap2.count(s2[i]) == 0)
                umap2[s2[i]] = 1;
            else
                umap2[s2[i]]++;

        // slide
        int left = 0;
        int right = n;
        while (right <= m) {
            bool flag = true;
            for (unordered_map<char, int>::iterator it = umap1.begin(); it != umap1.end(); it++)
                if (it->second != umap2[it->first]) {       // mismatch
                    flag = false;
                    break;
                }

            if (flag)                                       // all good
                return true;
            
            umap2[s2[left]]--;                              // decrement count at left
            if (umap2.count(s2[right]) == 0)                // increment count at right
                umap2[s2[right]] = 1;
            else
                umap2[s2[right]]++;
            left++;                                         // move forward
            right++;                                        // move forward
        }

        return false;
    }
};

int main() {
    Solution *s  = new Solution();

    string s1 = "ab";
    string s2 = "eidbaooo";
    printf("%d\n", s->checkInclusion(s1, s2));

    string s3 = "ab";
    string s4 = "eidboaoo";
    printf("%d\n", s->checkInclusion(s3, s4));

    string s5 = "adc";
    string s6 = "dcda";
    printf("%d\n", s->checkInclusion(s5, s6));
}