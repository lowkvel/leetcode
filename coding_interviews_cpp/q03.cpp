/*
    找出数组中重复的数字。

    在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
    数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
    请找出数组中任意一个重复的数字。

    输入：[2, 3, 1, 0, 2, 5, 3]
    输出：2 或 3

    限制：2 <= n <= 100000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>
# include <unordered_map>

using namespace std;

class Solution {
public:
    // map
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) 
            if (umap.count(nums[i]) != 0)
                return nums[i];
            else
                umap.insert(make_pair(nums[i], 1));
        return -1;
    }

    // pigeonhole principle
    /*
        题目明确说明了数组长度为n，范围为 n-1，也就是若无重复元素排序后下标0123对应的数字就应该是0123；
        对数组排序，其实也就是让萝卜归位，1号坑要放1号萝卜，2号坑要放2号萝卜......排序过程中查找有无重复元素。
        
        1. 先考虑没有重复元素的情况：
                nums[i]     3  1  0  2    萝卜   
                    i       0  1  2  3    坑  
            0号坑说我要的是0号萝卜，不要3号萝卜，所以会去和3号坑的萝卜交换，因为如果0号坑拿了3号坑的3号萝卜，那说明3号坑装的也肯定是别人家的萝卜，所以要跟3号坑换，
    
            换完是这样的：
                nums[i]     2  1  0  3    萝卜  
                    i       0  1  2  3    坑 
            然而0号坑还没找到自己的萝卜，它不要2号萝卜，又去和2号坑的萝卜交换，
    
            换完是这样的：
                nums[i]     0  1  2  3    萝卜 
                    i       0  1  2  3    坑  
            这时候刚好就是一一对应的，交换过程也不会出现不同坑有相同编号的萝卜。要注意交换用的是while，也就是0号坑只有拿到0号萝卜，1号坑才能开始找自己的萝卜。

        2. 如果有重复元素，例如：
                nums[i]     1  2  3  2    萝卜
                    i       0  1  2  3    坑
            同样的，0号坑不要1号，先和1号坑交换，
        
            交换完这样的：
                nums[i]     2  1  3  2    萝卜
                    i       0  1  2  3    坑
            0号坑不要2号萝卜，去和2号坑交换，
        
            交换完这样的：
                nums[i]     3  1  2  2    萝卜
                    i       0  1  2  3    坑
            0号坑不要3号萝卜，去和3号坑交换，
        
            交换完这样的：
                nums[i]     2  1  2  3    萝卜
                    i       0  1  2  3    坑
            0号坑不要2号萝卜，去和2号坑交换，结果发现你2号坑也是2号萝卜，那我还换个锤子，同时也说明有重复元素出现。

        来源：力扣（LeetCode）
        链接：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/solution/yuan-di-zhi-huan-shi-jian-kong-jian-100-by-derrick/705525
    */
    int findRepeatNumber2(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == i) {
                i++;
                continue;
            }
            if (nums[nums[i]] == nums[i])
                return nums[i];
            swap(nums[i], nums[nums[i]]);
        }
        return -1;
    }
};

int main() {
    Solution *s = new Solution();

}