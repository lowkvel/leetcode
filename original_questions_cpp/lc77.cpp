/*
    77. 组合

    给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

    你可以按 任何顺序 返回答案。

    示例 1：
        输入：n = 4, k = 2
        输出：
            [
                [2,4],
                [3,4],
                [2,3],
                [1,2],
                [1,3],
                [1,4],
            ]

    示例 2：
        输入：n = 1, k = 1
        输出：[[1]]
    
    提示：
        1 <= n <= 20
        1 <= k <= n

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/combinations
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>
# include <stack>

using namespace std;

/*
    重点概括：
        如果解决一个问题有多个步骤，每一个步骤有多种方法，题目又要我们找出所有的方法，可以使用回溯算法；
        回溯算法是在一棵 树 上的 深度优先遍历（因为要找所有的解，所以需要遍历）；
        组合问题，相对于排列问题而言，不计较一个组合内元素的顺序性（即 [1, 2, 3] 与 [1, 3, 2] 认为是同一个组合），因此很多时候需要按某种顺序展开搜索，这样才能做到不重不漏。
    作者：liweiwei1419
    链接：https://leetcode-cn.com/problems/combinations/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-ma-/
    来源：力扣（LeetCode）
    著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
    // recursion according to starting point
    /* 
        方法一：根据搜索起点画出二叉树
        
            既然是树形问题上的 深度优先遍历，因此首先画出树形结构。
            例如输入：n = 4, k = 2，我们可以发现如下递归结构：
                如果组合里有 1 ，那么需要在 [2, 3, 4] 里再找 1 个数；
                如果组合里有 2 ，那么需要在 [3, 4] 里再找 1 个数。
                    注意：这里不能再考虑 1，因为包含 1 的组合，在第 1 种情况中已经包含。
            依次类推（后面部分省略），以上描述体现的 递归 结构是：在以 n 结尾的候选数组里，选出若干个元素。
            画出递归结构如下图：
                                          在 [1, 2, 3, 4] 中选出 2 个数字
                    /                      |                         |                  \
                选 1                      选 2                      选 3                  选 4
              /                            |                        |                      \
            在 [2, 3, 4] 中选出 1 个数字    在 [3, 4] 中选出 1 个数字   在 [4] 中选出 1 个数字      在 [] 中选出 1 个数字
            |       |       |              |       |                |    
            选 2    选 3    选 4           选 3    选 4              选 4
            |       |       |              |       |                |  
            [1, 2] [1, 3]  [1, 4]        [2, 3]  [2, 4]            [3, 4]

            每一个叶子结点都是一个combination结果。

        说明：
            叶子结点的信息体现在从根结点到叶子结点的路径上，因此需要一个表示路径（所选数字）的变量 path，它是一个列表，特别地，path 是一个栈；
            每一个结点递归地在做同样的事情，区别在于搜索起点，因此需要一个变量 start ，表示在区间 [begin, n] 里选出若干个数的组合；
            
            可能有一些分支没有必要执行，我们放在优化中介绍。

        作者：liweiwei1419
        链接：https://leetcode-cn.com/problems/combinations/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-ma-/
        来源：力扣（LeetCode）
        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

    */
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ans;
        if (k <= 0 || n < k)        // invalid input
            return ans;

        vector<int> path;            // store recursive paths pushed into
        dfs(n, k, 1, path, ans);
        return ans;
    }

    void dfs(int n, int k, int startingIndex, vector<int> &path, vector<vector<int> > &ans) {
        if (path.size() == k) {     // k elements reached
            ans.push_back(path);    // one combination found
            return;                 // return back to previous level
        }

        for (int i = startingIndex; i <= n; i++) {
            path.push_back(i);              // push current index into path
            dfs(n, k, i + 1, path, ans);    // recursion from next index
            path.pop_back();                // pop current index from path, then go to next index from for loop
        }
    }

    // recursion according to starting point with optimization
    /*
        剪枝方案

        事实上，如果 n = 7, k = 4，从 5 开始搜索就已经没有意义了，
        这是因为：即使把 5 选上，后面的数只有 6 和 7，一共就 3 个候选数，凑不出 4 个数的组合。因此，搜索起点有上界。

        分析搜索起点的上界，其实是在深度优先 遍历的过程中 剪枝，剪枝可以避免不必要的遍历，剪枝剪得好，可以大幅度节约算法的执行时间。

        容易知道：搜索起点 和【当前还需要选几个数】有关，而当前还需要选几个数与【已经选了几个数】有关，即与 path 的长度相关。
        可以归纳出：
            搜索起点的上界 + 接下来要选择的元素个数 - 1 = n，其中，接下来要选择的元素个数 = k - path.size()，
                整理得到：搜索起点的上界 = n - (k - path.size()) + 1
            所以，我们的剪枝过程就是：把 i <= n 改成 i <= n - (k - path.size()) + 1 

        作者：liweiwei1419
        链接：https://leetcode-cn.com/problems/combinations/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-ma-/
        来源：力扣（LeetCode）
        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    */
    vector<vector<int> > combine2(int n, int k) {
        vector<vector<int> > ans;
        if (k <= 0 || n < k)        // invalid input
            return ans;

        vector<int> path;
        dfs2(n, k, 1, path, ans);
        return ans;
    }

    void dfs2(int n, int k, int startingIndex, vector<int> &path, vector<vector<int> > &ans) {
        if (path.size() == k) {     // k elements reached
            ans.push_back(path);    // one combination found
            return;                 // return back to previous level
        }

        for (int i = startingIndex; i <= n - (k - path.size()) + 1; i++) {      // optimization here, no need to search if there is not enough elements left to satisfy k elements
            path.push_back(i);
            dfs2(n, k, i + 1, path, ans);
            path.pop_back();
        }
    }

    // recursion according to current element is choosed or not
    /*
        可以按照每一个数选与不选画出二叉树，二叉树最多 n 层。同样可以剪枝。剪枝的思路请见下图「剪枝条件 ② 的加强」。
                             [ ]
                /                             \
              选1                             不选1
              /                                  \
            [1]                                  [ ]
            / \                            /             \
          选2 不选2                      选2               不选2
          /    \                       /                   \
        [1, 2]  [1]                  [2]                    [ ]
                / \                  / \                    / \
            选3 不选3               选3 不选3               选3 不选3 
            /     \                 /     \                /     \
            [1, 3]  [1]          [2, 3]   [2]            [3]     [ ]
                    / \                   / \            / \
                选4 不选4                选4 不选4       选4 不选4  
                /     \                 /     \        /     \
                [1, 4]  [1]           [2, 4]  [2]    [3, 4]  [3]
    */
    vector<vector<int> > combine3(int n, int k) {
        vector<vector<int> > ans;
        if (k <= 0 || k > n)        // invalid input
            return ans;

        vector<int> path;
        dfs3(n, k, 1, path, ans);
        return ans;
    }

    void dfs3(int n, int k, int startingIndex, vector<int> &path, vector<vector<int> > &ans) {
        if (k == 0) {                       // k decrement to 0
            ans.push_back(path);            // one combination found
            return;                         // return back to previous level
        }

        if (startingIndex > n)              // edge case, wont be able to choose a int outside of range n
            return;

        // if (startingIndex > n - k + 1)      // optimized edge case, wont be able to choose a int if not enough left
        //     return;

        
        // we choose current index into result 
        // add it into path (decrement remaining element count (k) to be choosed), dive in, pop out
        path.push_back(startingIndex);
        dfs3(n, k - 1, startingIndex + 1, path, ans);
        path.pop_back();

        // we dont choose current index into result, dive into next index directly
        dfs3(n, k, startingIndex + 1, path, ans);
    }
};

int main() {

}