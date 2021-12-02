/*
    17. 打印从1到最大的n位数

    输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。
    比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

    示例 1:
        输入: n = 1
        输出: [1,2,3,4,5,6,7,8,9]
    
    说明：
        用返回一个整数列表来代替打印
        n 为正整数

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    // brute force
    vector<int> printNumbers(int n) {
        int steps = 1;
        for (int i = 0; i < n; i++)
            steps = steps * 10;
        steps--;

        vector<int> ans(steps, 0);
        for (int i = 1; i <= steps; i++)
            ans[i - 1] = i;
    
        return ans;
    }

    // divide and conquer, permutation of 0-9 with length n, pre-0s removed, string implementation
    vector<int> printNumbers2(int n) {
        vector<int> ans;
        if (n <= 0)
            return ans;

        string s(n, '0');                           // initialize s to n 0s
        for (int i = 0; i <= 9; ++i) {              // 
            s[0] = i + '0';
            permutation(s, s.length(), 1, ans);
        }

        return ans;
    }

    void permutation(string &s, int length, int pos, vector<int> &ans) {
        if (pos == length) {                        // length n reached, add to ans
           addToAns(s, ans);
           return; 
        }

        for(int i = 0; i <= 9; ++i) {               // loop for current digit
            s[pos] = i + '0';
            permutation(s, length, pos + 1, ans);   // dive into next digit
        }
    }

    void addToAns(string s, vector<int> &ans) {
        bool pre0s = true;
        string temp = "";
        for (int i = 0; i < s.length(); ++i) {
            if (pre0s && s[i] != '0')               // not pre-0s found
                pre0s = false;
            if (!pre0s)                             // add to string temp
                temp += s[i];
        }

        if (temp != "")                             // transform into int, exclude 00..0 for stoi() to prevent exception
            ans.push_back(stoi(temp));
    }
};

int main() {
    Solution *s = new Solution();

    s->printNumbers2(2);
}
