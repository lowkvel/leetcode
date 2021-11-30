/*
    20. 表示数值的字符串

    请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。

    数值（按顺序）可以分成以下几个部分：
        若干空格
        一个 小数 或者 整数
        （可选）一个 'e' 或 'E' ，后面跟着一个 整数
        若干空格

    小数（按顺序）可以分成以下几个部分：
        （可选）一个符号字符（'+' 或 '-'）
        下述格式之一：
        至少一位数字，后面跟着一个点 '.'
        至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
        一个点 '.' ，后面跟着至少一位数字

    整数（按顺序）可以分成以下几个部分：
        （可选）一个符号字符（'+' 或 '-'）
        至少一位数字

    部分数值列举如下：
        ["+100", "5e2", "-123", "3.1416", "-1E-16", "0123"]

    部分非数值列举如下：
        ["12e", "1a3.14", "1.2.3", "+-5", "12e+5.4"]
     

    示例 1：
        输入：s = "0"
        输出：true

    示例 2：
        输入：s = "e"
        输出：false

    示例 3：
        输入：s = "."
        输出：false

    示例 4：
        输入：s = "    .1  "
        输出：true
     
    提示：
        1 <= s.length <= 20
        s 仅含英文字母（大写和小写），数字（0-9），加号 '+' ，减号 '-' ，空格 ' ' 或者点 '.' 。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <unordered_map>

using namespace std;

class Solution {
public:
    enum State {
        STATE_INITIAL,
        STATE_INT_SIGN,
        STATE_INTEGER,
        STATE_POINT_WITH_INT,
        STATE_POINT_WITHOUT_INT,
        STATE_FRACTION,
        STATE_EXPONENT,
        STATE_EXPONENT_SIGN,
        STATE_EXPONENT_NUMBER,
        STATE_END
    };

    enum CharType {
        CHAR_NUMBER,
        CHAR_EXPONENT,
        CHAR_POINT,
        CHAR_SIGN,
        CHAR_SPACE,
        CHAR_ILLEGAL
    };

    CharType toCharType(char c) {
        if (c >= '0' && c <= '9')
            return CHAR_NUMBER;
        else if (c == 'e' || c == 'E')
            return CHAR_EXPONENT;
        else if (c == '.')
            return CHAR_POINT;
        else if (c == '+' || c == '-')
            return CHAR_SIGN;
        else if (c == ' ')
            return CHAR_SPACE;
        else
            return CHAR_ILLEGAL;
    }

    bool isNumber(string s) {
        unordered_map<State, unordered_map<CharType, State> > trans {
            {
                STATE_INITIAL, {
                    {CHAR_SPACE, STATE_INITIAL},
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_POINT, STATE_POINT_WITHOUT_INT},
                    {CHAR_SIGN, STATE_INT_SIGN}
                }
            }, {
                STATE_INT_SIGN, {
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_POINT, STATE_POINT_WITHOUT_INT}
                }
            }, {
                STATE_INTEGER, {
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_EXPONENT, STATE_EXPONENT},
                    {CHAR_POINT, STATE_POINT_WITH_INT},
                    {CHAR_SPACE, STATE_END}
                }
            }, {
                STATE_POINT_WITH_INT, {
                    {CHAR_NUMBER, STATE_FRACTION},
                    {CHAR_EXPONENT, STATE_EXPONENT},
                    {CHAR_SPACE, STATE_END}
                }
            }, {
                STATE_POINT_WITHOUT_INT, {
                    {CHAR_NUMBER, STATE_FRACTION}
                }
            }, {
                STATE_FRACTION, {
                    {CHAR_NUMBER, STATE_FRACTION},
                    {CHAR_EXPONENT, STATE_EXPONENT},
                    {CHAR_SPACE, STATE_END}
                }
            }, {
                STATE_EXPONENT, {
                    {CHAR_NUMBER, STATE_EXPONENT_NUMBER},
                    {CHAR_SIGN, STATE_EXPONENT_SIGN}
                }
            }, {
                STATE_EXPONENT_SIGN, {
                    {CHAR_NUMBER, STATE_EXPONENT_NUMBER}
                }
            }, {
                STATE_EXPONENT_NUMBER, {
                    {CHAR_NUMBER, STATE_EXPONENT_NUMBER},
                    {CHAR_SPACE, STATE_END}
                }
            }, {
                STATE_END, {
                    {CHAR_SPACE, STATE_END}
                }
            }
        };

        int len = s.length();
        State st = STATE_INITIAL;

        for (int i = 0; i < len; i++) {
            CharType tp = toCharType(s[i]);
            if (trans[st].find(tp) == trans[st].end())
                return false;
            else
                st = trans[st][tp];
        }

        return st == STATE_INTEGER || st == STATE_POINT_WITH_INT ||
               st == STATE_FRACTION || st == STATE_EXPONENT_NUMBER || st == STATE_END;
    }
};

int main() {

}