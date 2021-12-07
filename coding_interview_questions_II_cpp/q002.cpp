/*
    002. 二进制加法

    给定两个 01 字符串 a 和 b ，请计算它们的和，并以二进制字符串的形式输出。

    输入为 非空 字符串且只包含数字 1 和 0。

    示例 1:
        输入: a = "11", b = "10"
        输出: "101"

    示例 2:
        输入: a = "1010", b = "1011"
        输出: "10101"
    
    提示：
        每个字符串仅由字符 '0' 或 '1' 组成。
        1 <= a.length, b.length <= 10^4
        字符串如果不是 "0" ，就都不含前导零。
    
    注意：本题与主站 67 题相同：https://leetcode-cn.com/problems/add-binary/

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/JFETK5
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>

using namespace std;

class Solution {
public:
    // simulation
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());    // reverse for easier manipulation
        reverse(b.begin(), b.end());    // reverse for easier manipulation
        
        string ans = "";
        int carryBit = 0;
        int maxLength = max(a.size(), b.size());                        // important here
        for (int i = 0; i < maxLength; i++) {
            carryBit = carryBit + (i < a.size() ? (a[i] == '1') : 0);   // add to carry bit if within size
            carryBit = carryBit + (i < b.size() ? (b[i] == '1') : 0);   // add to carry bit if within size
            ans.push_back(carryBit % 2 == 1 ? '1' : '0');               // get remainders
            carryBit = carryBit / 2;                                    // /2
        }
        if (carryBit == 1)                                              // get the last carry bit if exist
            ans.push_back('1');
        
        reverse(ans.begin(), ans.end());                                // reverse answer
        return ans;
    }

    // bit operation
    /*
        A  B  A^B  (A&B)<<1     +
        0  0   0      00     00+0=00
        0  1   1      00     00+1=01
        1  0   1      00     00+1=01
        1  1   0      10     10+0=10
    */
    string addBinary2(string a, string b) {

        /*
            python version code:

            x, y = int(a, 2), int(b, 2)
            while y:
                answer = x ^ y
                carry = (x & y) << 1
                x, y = answer, carry
            return bin(x)[2:]
        */

        return "";
    }
};

int main() {
    Solution *s = new Solution();
    string s1 = "1010";
    string s2 = "1011";
    cout << s->addBinary(s1, s2) << endl;
}
