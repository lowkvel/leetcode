/*
    136. 只出现一次的数字

    给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

    说明：
        你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

    示例 1:
        输入: [2,2,1]
        输出: 1

    示例 2:
        输入: [4,1,2,1,2]
        输出: 4

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/single-number
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>
# include <unordered_map>
# include <unordered_set>

using namespace std;

class Solution {
public:
    // ^: xor, n ^ 0 = n, n ^ n = 0
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
            ans = ans ^ nums[i];
        return ans;
    }

    // map, insert key & increment count, output the key with count == 1
    int singleNumber2(vector<int>& nums) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) 
            umap[nums[i]]++;

        for (unordered_map<int, int>::const_iterator it = umap.begin(); it != umap.end(); it++)
            if ((*it).second == 1)
                return (*it).first;

        return 0;
    }

    // set, insert then delete duplicates, output the last element
    int singleNumber3(vector<int>& nums) {
        unordered_set<int> uset;
        for (int i = 0; i < nums.size(); i++)
            if (uset.count(nums[i]) == 0)
                uset.insert(nums[i]);
            else
                uset.erase(nums[i]);

        return *uset.begin();
    }
};

int main() {
    cout << (2 ^ 1) << endl;
    cout << (2 ^ 2 ^ 2 ^ 2) << endl;
    cout << (2 ^ 3) << endl;

    Solution *s = new Solution();

    vector<int> v1;
    v1.push_back(2);
    v1.push_back(2);
    v1.push_back(1);

    cout << s->singleNumber(v1) << endl;
    cout << s->singleNumber2(v1) << endl;
    cout << s->singleNumber3(v1) << endl;

    vector<int> v2;
    v2.push_back(4);
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(1);
    v2.push_back(2);

    cout << s->singleNumber(v2) << endl;
    cout << s->singleNumber2(v2) << endl;
    cout << s->singleNumber3(v2) << endl;
}
