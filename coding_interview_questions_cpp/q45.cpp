/*
    45. 把数组排成最小的数

    输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

    示例 1:
        输入: [10,2]
        输出: "102"

    示例 2:
        输入: [3,30,34,5,9]
        输出: "3033459"
    
    提示:
        0 < nums.length <= 100

    说明:
        输出结果可能非常大，所以你需要返回一个字符串而不是整数
        拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> s;
        for (int i = 0; i < nums.size(); i++) 
            s.push_back(to_string(nums[i]));

        quickSort(s, 0, s.size() - 1);

        string ans = "";
        for (int i = 0; i < s.size(); i++)
            ans.append(s[i]);
        return ans;
    }

    void quickSort(vector<string> &s, int l, int r) {
        if (l >= r)
            return;

        int i = l;
        int j = r;
        while (i < j) {
            while (s[j] + s[l] >= s[l] + s[j] && i < j)
                j--;
            while (s[i] + s[l] <= s[l] + s[i] && i < j)
                i++;
            swap(s[i], s[j]);
        }
        swap(s[i], s[l]);

        quickSort(s, l, i - 1);
        quickSort(s, i + 1, r);
    }
};

int main() {

}
