/*
    003. 前n个数字二进制中1的个数

    给定一个非负整数 n ，请计算 0 到 n 之间的每个数字的二进制表示中 1 的个数，并输出一个数组。

    示例 1:
        输入: n = 2
        输出: [0,1,1]
        解释: 
            0 --> 0
            1 --> 1
            2 --> 10

    示例 2:
        输入: n = 5
        输出: [0,1,1,2,1,2]
        解释:
            0 --> 0
            1 --> 1
            2 --> 10
            3 --> 11
            4 --> 100
            5 --> 101
    
    说明 :
        0 <= n <= 10^5
     
    进阶:
        给出时间复杂度为 O(n*sizeof(integer)) 的解答非常容易。但你可以在线性时间 O(n) 内用一趟扫描做到吗？
        要求算法的空间复杂度为 O(n) 。
        你能进一步完善解法吗？要求在C++或任何其他语言中不使用任何内置函数（如 C++ 中的 __builtin_popcount ）来执行此操作。
     
    注意：本题与主站 338 题相同：https://leetcode-cn.com/problems/counting-bits/

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/w3tCBm
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    // simulation, Brian Kernighan algorithm, x & (x - 1)
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 0; i <= n; i++) 
            ans[i] = countOnes(i);
        return ans;
    }

    int countOnes(int n) {
        int counts = 0;
        while (n > 0) {
            n = n & (n - 1);    // the last 1 turns into 0 for the binary representation of n
            counts++;
        }
        return counts;
    }

    // dynamic programming, the least significant bit
    vector<int> countBits2(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; i++) 
            if (i % 2 == 1)                     
                ans[i] = ans[i / 2] + 1;        // odd number i has one more 1 at tail compared to i/2 (tail 1 removed)
                //ans[i] = ans[i - 1] + 1;      // OR odd number i has one more 1 at tail compared to i-1 (tail is 0)
            else                                
                ans[i] = ans[i / 2];            // even number i has same 1 counts compared to i/2 (tail 0 removed)

            //ans[i] = ans[i >> 1] + (i & 1);   // advanced version of above

        return ans;
    }

    // TODO dynamic programming, the most significant bit
    vector<int> countBits3(int n) {
        vector<int> ans(n + 1, 0);
        int msb = 0;
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0)         // the msb found, in the format with 10...0
                msb = i;
            ans[i] = ans[i - msb] + 1;      // i has one more 1 at head compared to i-msb 
        }
        return ans;
    }

    // TODO dynamic programming, the lest setting bit
    vector<int> countBits4(int n) {
        vector<int> ans(n + 1, 0);

        return ans;
    }
};

int main() {

}
