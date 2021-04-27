from typing import List


"""
    用两个队列实现栈

    用两个队列实现一个栈。
    栈的声明如下，请实现它的两个函数 appendTail 和 deleteTail ，分别完成在栈尾部插入整数和在栈尾部删除整数的功能。
    (若栈中没有元素，deleteTail 操作返回 -1 )

    示例 1：
        输入：
            ["CStack","appendTail","deleteTail","deleteTail"]
            [[],[3],[],[]]
        输出：[null,null,3,-1]

    示例 2：
        输入：
            ["CStack","deleteTail","appendTail","appendTail","deleteTail","deleteTail"]
            [[],[],[5],[2],[],[]]
        输出：
            [null,-1,null,null,2,5]

    提示：
        1 <= values <= 10000
        最多会对 appendTail、deleteTail 进行 10000 次调用

    来源：
    链接：
"""

# Your CStack object will be instantiated and called as such:
# obj = CStack()
# obj.appendTail(value)
# param_2 = obj.deleteTail()

# dual lists implement, ms, mb, time o(n), space o(n)
class CStack:

    def __init__(self):                                         # two lists initiation
        self.queue1 = []                                        # queue1 and queue2 will be used in turn for appending and deleting
        self.queue2 = []

    def appendTail(self, value: int) -> None:
        if not self.queue1:                                     # empty queue1, append to queue2 or queue1, take queue2 here
            self.queue2.append(value)
        else:                                                   # non-empty queue1, append to queue1
            self.queue1.append(value)

    def deleteTail(self) -> int:
        if not self.queue1:                                     # empty queue1, queue2 could be empty
            if not self.queue2:                                 # empty queue2 too, nothing to delete, return -1
                return -1
            for index in range(0, len(self.queue2)-1, 1):       # move all element except the last one from queue2 to queue1, return the last one
                self.queue1.append(self.queue2[index])
            temp = self.queue2[len(self.queue2)-1]
            self.queue2 = []
            return temp
        else:                                                   # non-empty queue1, queue2 must be empty
            for index in range(0, len(self.queue1)-1, 1):       # move all element except the last one from queue1 to queue2, return the last one
                self.queue2.append(self.queue1[index])
            temp = self.queue1[len(self.queue1)-1]
            self.queue1 = []
            return temp


def execution(command: List, value: List) -> List:
    
    if len(command) != len(value):              # deal with different length of two lists
        return 'incorrect input'

    obj = CStack()                              # result initiation
    result = []
    initiated = False
    for c, v in zip(command, value):
        if c == 'CStack':                       # initiated the list
            if initiated == False:              # initiate the list at start only
                initiated = True
                result.append(None)             # initiated, append None to result
            else:
                return 'incorrect input'
        elif c == 'appendTail':                 # append tail, append None to result
            obj.appendTail(v[0])
            result.append(None)
        elif c == 'deleteTail':                 # delete tail, append the returned element or -1 to result
            temp = obj.deleteTail()
            result.append(temp)
        else:                                   # incorrect input if exists
            return 'incorrect input'
    return result                               # return the result


if __name__ == '__main__':

    input = [
        [   
            ["CStack","appendTail","deleteTail","deleteTail"], 
            [[],[3],[],[]], 
            # [null,null,3,-1]
        ], 
        [
            ["CStack","appendTail","deleteTail","deleteTail","deleteTail"],
            [[],[3],[],[],[]],
            # [null,null,3,-1,-1]
        ],
        [   
            ["CStack","deleteTail","appendTail","appendTail","deleteTail","deleteTail"], 
            [[],[],[5],[2],[],[]],
            # [null,-1,null,null,2,5]
        ],

    ]

    print('-----')
    for item in input:
        print(execution(item[0], item[1]))

        print('-----')