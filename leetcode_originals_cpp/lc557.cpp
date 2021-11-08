/*
    557. 反转字符串中的单词III

    给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

    示例：
        输入："Let's take LeetCode contest"
        输出："s'teL ekat edoCteeL tsetnoc"
     
    提示：
        在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/reverse-words-in-a-string-iii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        if (s[s.size() - 1] != ' ')
            s = s + ' ';

        int start = 0;
        for (int i = 0; i < s.size(); i++) 
            if (s[i] == ' ') {
                int end = i;

                int left = start;
                int right = end - 1;
                while (left < right) {
                    char temp = s[left];
                    s[left] = s[right];
                    s[right] = temp;

                    left++;
                    right--;
                }

                start = i + 1;
            }
        return s.substr(0, s.size() - 1);
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->reverseWords(" ") << endl;
}