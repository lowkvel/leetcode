/*
    350. 两个数组的交集II

    给定两个数组，编写一个函数来计算它们的交集。

    示例 1：
        输入：nums1 = [1,2,2,1], nums2 = [2,2]
        输出：[2,2]

    示例 2:
        输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
        输出：[4,9]

    说明：
        输出结果中每个元素出现的次数，应与元素在两个数组中出现次数的最小值一致。
        我们可以不考虑输出结果的顺序。

    进阶：
        如果给定的数组已经排好序呢？你将如何优化你的算法？
        如果 nums1 的大小比 nums2 小很多，哪种方法更优？
        如果 nums2 的元素存储在磁盘上，内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/intersection-of-two-arrays-ii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>
# include <unordered_map>

using namespace std;

class Solution {
public:
    // map
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // go from the smaller one first, memory saving, time saving
        if (nums1.size() > nums2.size())
            return intersect(nums2, nums1);

        // build map, <value, count>
        unordered_map<int, int> umap;
        // for (int i = 0; i < nums1.size(); i++) 
        //     if (umap.count(nums1[i]) > 0)               // key exists
        //         umap[nums1[i]]++;
        //     else                                        // key not exists
        //         umap.insert(make_pair(nums1[i], 1));
        for (int num : nums1) 
            ++umap[num];

        // check for intersection
        vector<int> ans;
        for (int i = 0; i < nums2.size(); i++)
            if (umap.count(nums2[i]) > 0) {             // key exists
                ans.push_back(nums2[i]);
                umap[nums2[i]]--;                       // decrement apperance count by 1

                if (umap[nums2[i]] == 0)                // remove key
                    umap.erase(nums2[i]);
            }

        // return answer
        return ans;
    }

    // assuming two vectors are sorted, sort, dual pointers
    vector<int> intersect2(vector<int>& nums1, vector<int>& nums2) {
        // sort
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        // dual pointers
        int len1 = nums1.size();
        int len2 = nums2.size();
        int index1 = 0;
        int index2 = 0;
        vector<int> ans;

        while (index1 < len1 && index2 < len2) 
            if (nums1[index1] < nums2[index2])          // move index1 forward
                index1++;
            else if (nums1[index1] > nums2[index2])     // move index2 forward
                index2++;
            else {                                      // intersection instance found, move both forward
                ans.push_back(nums1[index1]);
                index1++;
                index2++;
            }
        
        // return
        return ans;
    }
};

int main() {
    Solution *s = new Solution();

    int a1[] = {1,2,2,1};   vector<int> v1(a1, a1 + 4);
    int a2[] = {2,2};       vector<int> v2(a2, a2 + 2);
    vector<int> ans(s->intersect(v1, v2));
    for (int i = 0; i < ans.size(); i++)
        printf("%d, ", ans[i]);
    printf("\n");
}
