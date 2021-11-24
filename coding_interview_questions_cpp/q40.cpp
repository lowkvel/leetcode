/*
    40. 最小的k个数
    
    输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

    示例 1：
        输入：arr = [3,2,1], k = 2
        输出：[1,2] 或者 [2,1]

    示例 2：
        输入：arr = [0,1,2,1], k = 1
        输出：[0]
     
    限制：
        0 <= k <= arr.length <= 10000
        0 <= arr[i] <= 10000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>
# include <queue>

using namespace std;

class Solution {
public:
    // sort, then get first k
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());

        vector<int> ans(k, 0);
        for (int i = 0; i < k; i++)
            ans[i] = arr[i];
        return ans;
    }

    // heap
    vector<int> getLeastNumbers2(vector<int>& arr, int k) {
        vector<int> ans(k, 0);
        if (k == 0)
            return ans;

        priority_queue<int> q;
        for (int i = 0; i < k; i++)             // push first k elements into pri_q
            q.push(arr[i]);
        for (int i = k; i < arr.size(); i++)    // starts from k + 1, replace the largest element in pri_q with smaller element afterwards
            if (q.top() > arr[i]) {
                q.pop();
                q.push(arr[i]);
            }
        for (int i = 0; i < k; i++) {           // build ans vector
            ans[i] = q.top();
            q.pop();
        }

        return ans;
    }

    // quick sort like
    vector<int> getLeastNumbers3(vector<int>& arr, int k) {

    }
};

int main() {

}