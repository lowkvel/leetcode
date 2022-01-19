/*
    169. 多数元素

    给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

    你可以假设数组是非空的，并且给定的数组总是存在多数元素。

    示例 1：
        输入：[3,2,3]
        输出：3

    示例 2：
        输入：[2,2,1,1,1,2,2]
        输出：2
    
    进阶：
        尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/majority-element
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>
# include <unordered_map>

using namespace std;

class Solution {
public:
    // map
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++)
            if (umap.count(nums[i]) == 0)
                umap.insert(make_pair(nums[i], 1));
            else 
                umap[nums[i]]++;

        for (unordered_map<int, int>::const_iterator it = umap.begin(); it != umap.end(); it++)
            if ((*it).second > nums.size() / 2)
                return (*it).first;

        return 0;
    }

    // map, advanced version
    int majorityElement2(vector<int>& nums) {
        unordered_map<int, int> umap;
        int ans = 0;
        int cnt = 0;
        for (int num: nums) {
            umap[num]++;
            if (umap[num] > cnt) {
                ans = num;
                cnt = umap[num];
            }
        }
        return ans;
    }

    // sort, then nums[n/2]
    int majorityElement3(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }

    // Boyer–Moore majority vote algorithm
    int majorityElement4(vector<int>& nums) {
        int ans = 0;
        int cnt = 0;

        for (int num: nums) {
            if (cnt == 0)
                ans = num;
            
            if (num == ans)
                cnt++;
            else 
                cnt--;
        }

        return ans;
    }
};

int main() {
    Solution *s = new Solution();

    vector<int> v1;
    v1.push_back(3);
    v1.push_back(2);
    v1.push_back(3);

    cout << s->majorityElement(v1) << endl;
    cout << s->majorityElement2(v1) << endl;
    cout << s->majorityElement3(v1) << endl;
    cout << s->majorityElement4(v1) << endl;

    vector<int> v2;
    v2.push_back(2);
    v2.push_back(2);
    v2.push_back(1);
    v2.push_back(1);
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(2);

    cout << s->majorityElement(v2) << endl;
    cout << s->majorityElement2(v2) << endl;
    cout << s->majorityElement3(v2) << endl;
    cout << s->majorityElement4(v2) << endl;
}