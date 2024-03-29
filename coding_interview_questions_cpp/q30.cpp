/*
    包含min函数的栈

    定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

    示例:
        MinStack minStack = new MinStack();
        minStack.push(-2);
        minStack.push(0);
        minStack.push(-3);
        minStack.min();         --> 返回 -3
        minStack.pop();
        minStack.top();         --> 返回 0
        minStack.min();         --> 返回 -2

    提示：
        各函数的调用总次数不超过 20000 次

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

# include <iostream>
# include <stack>

using namespace std;

class MinStack {
public:
    stack<int> sstd;                            // used for store all data
    stack<int> smin;                            // used for store min data (non-increasing order) 

public:
    /** initialize your data structure here. */
    MinStack() {
        while (!sstd.empty())
            sstd.pop();
        while (!smin.empty())
            smin.pop();
    }
    
    void push(int x) {
        if (smin.empty() || x <= smin.top())    // empty min data stack, or current x <= top of min data stack
            smin.push(x);

        sstd.push(x);                           // push into all data stack
    }
    
    void pop() {
        if (smin.top() == sstd.top())           // if the top of min data stack is equal to top of all data stack
            smin.pop();                         // pop the top of min data stack

        sstd.pop();                             // pop from all data stack
    }
    
    int top() {
        return sstd.top();                      // return top of all data stack
    }
    
    int min() {
        return smin.top();                      // return top of min data stack
    }
};

void execution(string c[], int v[][1], int len) {
    MinStack *ms;
    for (int i = 0; i < len; i++) {
        if (c[i] == "MinStack")     ms = new MinStack();
        if (c[i] == "push")         ms->push(v[i][0]);
        if (c[i] == "pop")          ms->pop();
        if (c[i] == "min")          printf("%d, ", ms->min());
        if (c[i] == "top")          printf("%d, ", ms->top());
    }  
    printf("\n"); 
}

int main() {
    string c1[] = {"MinStack","push","push","push","min","pop","top","min"}; 
    int v1[][1] = {{},{-2},{0},{-3},{},{},{},{}};
    execution(c1, v1, (sizeof(c1) / sizeof(c1[0])));
}
