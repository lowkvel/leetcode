/*
    连续子数组的最大和

    输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
    要求时间复杂度为O(n)。

    示例1:
        输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
        输出: 6
        解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
    
    提示：
        1 <= arr.length <= 10^5
        -100 <= arr[i] <= 100

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    // dynamic programming, with auxilary array
    int maxSubArray(vector<int>& nums) {
        vector<int> sum;
        sum.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) 
            sum.push_back(max(sum[i - 1] + nums[i], nums[i]));      // sum[i] represents max sum calculated ends with nums[i]
        
        int maxsum = sum[0];
        for (int i = 0; i < sum.size(); i++)
            if (sum[i] > maxsum)
                maxsum = sum[i];
        
        return maxsum;
    }

    // dynamic programming, without auxilary array
    int maxSubArray2(vector<int>& nums) {
        int preMaxsum = 0;                                          // used for max sum till previous element position nums[i - 1]
        int maxsum = nums[0];                                       // used for global max sum
        for (int i = 0; i < nums.size(); i++) {
            preMaxsum = max(preMaxsum + nums[i], nums[i]);          // update preMaxsum for current position according to state transfer function
            maxsum = max(maxsum, preMaxsum);                        // update global max sum
        }
        return maxsum;
    }

    // Segment Tree
    int maxSubArray3(vector<int>& nums) {


        return 0;
    }
};

int main() {

}