/*
    39. 数组中出现次数超过一半的数字

    数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。

    你可以假设数组是非空的，并且给定的数组总是存在多数元素。

    示例 1:
        输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
        输出: 2
    
    限制：
        1 <= 数组长度 <= 50000

    注意：本题与主站 169 题相同：https://leetcode-cn.com/problems/majority-element/

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>
# include <unordered_map>

using namespace std;

class Solution {
public:
    // hash
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> umap;

        for (int n: nums) {
            if (umap.count(n) == 0)
                umap.insert(make_pair(n, 1));
            else
                umap[n]++;

            if (umap[n] > nums.size() / 2)
                return n;
        }

        return 0;
    }

    // sort, then take element at position n/2
    int majorityElement2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }

    // Boyer-Moore votes
    /*
        摩尔投票法
        
        推论一： 若记 众数 的票数为 +1 ，非众数 的票数为 −1 ，则一定有所有数字的 票数和 > 0 。
        推论二： 若数组的前 a 个数字的 票数和 = 0 ，则 数组剩余 (n−a) 个数字的 票数和一定仍 >0 ，即后 (n−a) 个数字的 众数仍为 x 。

        根据以上推论，记数组首个元素为 n_1 ，众数为 x ，遍历并统计票数。
        当发生 票数和 = 0 时，剩余数组的众数一定不变 ，这是由于：
            当 n_1 = x ：抵消的所有数字中，有一半是众数 x 。
            当 n_1 != x ：抵消的所有数字中，众数 x 的数量最少为 0 个，最多为一半。
        利用此特性，每轮假设发生 票数和 = 0 时都可以 缩小剩余数组区间 。当遍历完成时，最后一轮假设的数字即为众数。

        算法流程:

        初始：票数统计 votes = 0 ， 众数 x；
        循环：遍历数组 nums 中的每个数字 num ；
            当 票数 votes 等于 0 ，则假设当前数字 num 是众数；
            当 num = x 时，票数 votes 自增 1 ；当 num != x 时，票数 votes 自减 1 ；
        返回：返回 x 即可；

        作者：jyd
        链接：https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/solution/mian-shi-ti-39-shu-zu-zhong-chu-xian-ci-shu-chao-3/
        来源：力扣（LeetCode）
        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    */
    int majorityElement3(vector<int>& nums) {
        int cadidate = 0;
        int votes = 0;
        for (int num: nums) {
            if (votes == 0)                             // assume current num is the mode if votes is 0, array size shrinking when votes reaches 0
                cadidate = num;
            votes = votes + (num == cadidate ? 1 : -1); // increment if current num is assumed mode while decrement if not
        }
        return cadidate;                                // the last candidate is the mode
    }
};

int main() {

}
