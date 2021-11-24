/*
    41. 数据流中的中位数

    如何得到一个数据流中的中位数？
    如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
    如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

    例如，
        [2,3,4] 的中位数是 3
        [2,3] 的中位数是 (2 + 3) / 2 = 2.5

    设计一个支持以下两种操作的数据结构：
        void addNum(int num) - 从数据流中添加一个整数到数据结构中。
        double findMedian() - 返回目前所有元素的中位数。

    示例 1：
        输入：
        ["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
        [[],[1],[2],[],[3],[]]
        输出：[null,null,null,1.50000,null,2.00000]

    示例 2：
        输入：
        ["MedianFinder","addNum","findMedian","addNum","findMedian"]
        [[],[2],[],[3],[]]
        输出：[null,null,2.00000,null,2.50000]
    
    限制：
        最多会对 addNum、findMedian 进行 50000 次调用。
        
    注意：本题与主站 295 题相同：https://leetcode-cn.com/problems/find-median-from-data-stream/

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

# include <iostream>
# include <queue>

using namespace std;

// priority queue
class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int> > maxheap;       // max heap, store smaller data, top is its max
    priority_queue<int, vector<int>, greater<int> > minheap;    // min heap, store larger data, top is its min

    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    // maintain data balance, make sure max from max heap is smaller or equal to min from min heap
    void addNum(int num) {
        if (maxheap.size() == minheap.size()) { // m == n, add num to maxheap by doing following
            minheap.push(num);                  // push num to minheap
            maxheap.push(minheap.top());        // push min from minheap into maxheap
            minheap.pop();                      // pop min from minheap
        } else {                                // m > n, add num to minheap by doing following
            maxheap.push(num);                  // push num to maxheap
            minheap.push(maxheap.top());        // push max from maxheap into minheap
            maxheap.pop();                      // pop max from maxheap
        }
    }
    
    double findMedian() {
        if (maxheap.size() == minheap.size())
            return (maxheap.top() + minheap.top()) * 1.0 / 2;
        else
            return maxheap.top() * 1.0;
    }
};

int main() {

}