/*
    120. 三角形最小路径和

    给定一个三角形 triangle ，找出自顶向下的最小路径和。

    每一步只能移动到下一行中相邻的结点上。
    相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。
    也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。

    示例 1：
        输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
        输出：11
        解释：如下面简图所示：
            2
            3 4
            6 5 7
            4 1 8 3
        自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

    示例 2：
        输入：triangle = [[-10]]
        输出：-10
    
    提示：
        1 <= triangle.length <= 200
        triangle[0].length == 1
        triangle[i].length == triangle[i - 1].length + 1
        -10^4 <= triangle[i][j] <= 10^4
     
    进阶：
        你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题吗？

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/triangle
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        if (triangle.size() == 0)
            return 0;

        for (int i = 1; i < triangle.size(); i++) 
            for (int j = 0; j < triangle[i].size(); j++) 
                triangle[i][j] = triangle[i][j] + min(
                    (i - 1 >= 0 && j - 1 >= 0) ? triangle[i - 1][j - 1] : triangle[i - 1][j], 
                    (i - 1 >= 0 && j < triangle[i - 1].size()) ? triangle[i - 1][j] : triangle[i - 1][j - 1]
                );
       
        int ans = triangle[triangle.size() - 1][0];
        for (int i = 0; i < triangle[triangle.size() - 1].size(); i++)
            ans = min(ans, triangle[triangle.size() - 1][i]);
        return ans; 
    }
};

int main() {
    Solution *s = new Solution();

    vector<vector<int> > v;
    int a1[] = {2};             vector<int> v1(a1, a1 + 1); v.push_back(v1);
    int a2[] = {3, 4};          vector<int> v2(a2, a2 + 2); v.push_back(v2);
    int a3[] = {6, 5, 7};       vector<int> v3(a3, a3 + 3); v.push_back(v3);
    int a4[] = {4, 1, 8, 3};    vector<int> v4(a4, a4 + 4); v.push_back(v4);
    
    cout << s->minimumTotal(v) << endl;
}
