from typing import List

"""
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
"""

# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()

# dual lists implement, 380ms, 18.7mb, time o(n), space o(n)
class CQueue:

    def __init__(self):                                         # two lists initiation
        self.stack_in = []                                      # stack1 is used for appending
        self.stack_out = []                                     # stack2 is used for deleting

    def appendTail(self, value: int) -> None:
        self.stack_in.append(value)                             # append element to stack1

    def deleteHead(self) -> int:
        if not self.stack_out:                                  # empty stack2
            if not self.stack_in:                               # empty stack1 too, nothing left to delete, return -1
                return -1
            while self.stack_in:                                # move all elements from stack1 into stack2 backwards
                self.stack_out.append(self.stack_in.pop()) 
        return self.stack_out.pop()                             # pop the last element in stack2 and return it


def execution(command: List, value: List) -> List:
    
    if len(command) != len(value):              # deal with different length of two lists
        return 'incorrect input'

    obj = CQueue()                              # result initiation
    result = []
    initiated = False
    for c, v in zip(command, value):
        if c == 'CQueue':                       # initiated the list
            if initiated == False:              # initiate the list at start only
                initiated = True
                result.append(None)             # initiated, append None to result
            else:
                return 'incorrect input'
        elif c == 'appendTail':                 # append tail, append None to result
            obj.appendTail(v[0])
            result.append(None)
        elif c == 'deleteHead':                 # delete head, append the popped element or -1 to result
            temp = obj.deleteHead()
            result.append(temp)
        else:                                   # incorrect input if exists
            return 'incorrect input'
    return result                               # return the result


if __name__ == '__main__':

    input = [
        [   
            ["CQueue","appendTail","deleteHead","deleteHead"], 
            [[],[3],[],[]], 
            # [null,null,3,-1]
        ], 
        [
            ["CQueue","appendTail","deleteHead","deleteHead","deleteHead"],
            [[],[3],[],[],[]],
            # [null,null,3,-1,-1]
        ],
        [   
            ["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"], 
            [[],[],[5],[2],[],[]],
            # [null,-1,null,null,5,2]
        ],

    ]

    print('-----')
    for item in input:
        print(execution(item[0], item[1]))

        print('-----')
