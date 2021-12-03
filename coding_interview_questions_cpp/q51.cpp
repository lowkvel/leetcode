/*
    51. 数组中的逆序对

    在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
    输入一个数组，求出这个数组中的逆序对的总数。

    示例 1:
        输入: [7,5,6,4]
        输出: 5
    
    限制：
        0 <= 数组长度 <= 50000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> tmp(nums.size());
        return modifiedMergeSort(0, nums.size() - 1, nums, tmp);
    }

    int modifiedMergeSort(int l, int r, vector<int> &nums, vector<int> &tmp) {
        if (l >= r)     // element left <= 1, return 0
            return 0;

        // divide
        int m = l + (r - l) / 2;
        int ans = modifiedMergeSort(l, m, nums, tmp) +      // divide, left side
                  modifiedMergeSort(m + 1, r, nums, tmp);   // divide, right sidie

        // conquer
        int i = l;
        int j = m + 1;
        for (int k = l; k <= r; k++)
            tmp[k] = nums[k];
        for (int k = l; k <= r; k++) {
            if (i == m + 1)
                nums[k] = tmp[j++];
            else if (j == r + 1 || tmp[i] <= tmp[j])
                nums[k] = tmp[i++];
            else {
                nums[k] = tmp[j++];
                ans += m - i + 1;                           // 
            }
        }

        return ans;
    }
};

int main() {

}