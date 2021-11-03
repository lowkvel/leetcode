/*
    用两个栈实现队列

    用两个栈实现一个队列。
    队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。
    (若队列中没有元素，deleteHead 操作返回 -1 )

    示例 1：
        输入：
            ["CQueue","appendTail","deleteHead","deleteHead"]
            [[],[3],[],[]]
        输出：[null,null,3,-1]

    示例 2：
        输入：
            ["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
            [[],[],[5],[2],[],[]]
        输出：
            [null,-1,null,null,5,2]

    提示：
        1 <= values <= 10000
        最多会对 appendTail、deleteHead 进行 10000 次调用

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

# include <iostream>
# include <stack>
# include <vector>

using namespace std;

class CQueue {
public:
    stack<int> s1;                      // used for push
    stack<int> s2;                      // used for pop

public:
    CQueue() {
        while (!s1.empty())             // pop all element in s1
            s1.pop();
        while (!s2.empty())             // pop all element in s2
            s2.pop();
    }
    
    void appendTail(int value) {
        s1.push(value);                 // push elements into s1
    }
    
    int deleteHead() {
        if (s2.empty()) {               // no element for popping in s2
            while (!s1.empty()) {       // move all elements from s1 into s2
                s2.push(s1.top());      // push the top element of s1 into s2
                s1.pop();               // delete the top element of s1
            }
        }

        if (s2.empty())                 // no element exists
            return -1;
        else {
            int temp = s2.top();        // get the top of s2 for popping
            s2.pop();                   // pop it
            return temp;                // return it
        }
    }
};

void execution(string c[], int v[][1], int len) {
    CQueue *cq;
    for (int i = 0; i < len; i++) {
        if (c[i] == "CQueue") {
            cq = new CQueue();
            printf("null, ");
        }
        if (c[i] == "appendTail") {
            cq->appendTail(v[i][0]);
            printf("null, ");
        }
        if (c[i] == "deleteHead") 
            printf("%d, ", cq->deleteHead());
    }  
    printf("\n"); 
}

int main() {
    string c1[] = {"CQueue","appendTail","deleteHead","deleteHead"}; 
    int v1[][1] = {{},{3},{},{}};
    execution(c1, v1, (sizeof(c1) / sizeof(c1[0])));

    string c2[] = {"CQueue","appendTail","deleteHead","deleteHead","deleteHead"};
    int v2[][1] = {{},{3},{},{},{}};
    execution(c2, v2, (sizeof(c2) / sizeof(c2[0])));

    string c3[] = {"CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"};
    int v3[][1] = {{},{},{5},{2},{},{}};
    execution(c3, v3, (sizeof(c3) / sizeof(c3[0])));
}
