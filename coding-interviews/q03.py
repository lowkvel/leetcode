from typing import List

"""
找出数组中重复的数字。

在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
请找出数组中任意一个重复的数字。

输入：[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3

限制：2 <= n <= 100000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

class Solution:

    # dict, 72ms, 23.4mb, time o(n), space o(n), input remains intact
    def findRepeatNumber(self, nums: List[int]) -> int:

        # check for invalid input
        if nums is None:
            return "invalid input"
        for item in nums:
            if item > len(nums)-1 or item < 0:
                return "invalid input"

        # hash, using dict
        d = {}
        for item in nums:
            if item in d:
                return item
            else:
                d[item] = item
        return "no repeated item"

    # set, 68ms, 23.4mb, time o(n), space o(n), input remains intact
    def findRepeatNumber2(self, nums: List[int]) -> int:

        # check for invalid input
        if nums is None:
            return "invalid input"
        for item in nums:
            if item > len(nums)-1 or item < 0:
                return "invalid input"

        # set, python special, similar to hash
        s = set()
        for index in range(0, len(nums), 1):
            s.add(nums[index])
            if len(s) < index + 1:
                return nums[index]
        return "no repeated item"

    # sort, 88ms, 23.4mb, time o(nlogn), space o(1), input remains intact   
    def findRepeatNumber3(self, nums: List[int]) -> int:

        # check for invalid input
        if nums is None:
            return "invalid input"
        for item in nums:
            if item > len(nums)-1 or item < 0:
                return "invalid input"

        # sort, then compare
        nums_sorted = sorted(nums)
        for index in range(0, len(nums_sorted)-1, 1):
            if nums_sorted[index] == nums_sorted[index + 1]:
                return nums_sorted[index]
        return "no repeated item"

    # pigeonhole principle, 68ms, 23.4mb, time o(n), space o(1), input changes  
    def findRepeatNumber4(self, nums: List[int]) -> int:

        # pigeonhole principle
        # In mathematics, the pigeonhole principle states that 
        # if n items are put into m containers, with n > m, then at least one container must contain more than one item.
        
        # check for invalid input
        if nums is None:
            return "invalid input"
        for item in nums:
            if item > len(nums)-1 or item < 0:
                return "invalid input"

        """
            题目明确说明了数组长度为n，范围为 n-1，也就是若无重复元素排序后下标0123对应的数字就应该是0123；
            对数组排序，其实也就是让萝卜归位，1号坑要放1号萝卜，2号坑要放2号萝卜......排序过程中查找有无重复元素。
            
            1. 先考虑没有重复元素的情况：
                    nums[i]     3  1  0  2    萝卜   
                        i       0  1  2  3    坑  
                0号坑说我要的是0号萝卜，不要3号萝卜，所以会去和3号坑的萝卜交换，因为如果0号坑拿了3号坑的3号萝卜，那说明3号坑装的也肯定是别人家的萝卜，所以要跟3号坑换，
        
                换完是这样的：
                    nums[i]     2  1  0  3    萝卜  
                        i       0  1  2  3    坑 
                然而0号坑还没找到自己的萝卜，它不要2号萝卜，又去和2号坑的萝卜交换，
        
                换完是这样的：
                    nums[i]     0  1  2  3    萝卜 
                        i       0  1  2  3    坑  
                这时候刚好就是一一对应的，交换过程也不会出现不同坑有相同编号的萝卜。要注意交换用的是while，也就是0号坑只有拿到0号萝卜，1号坑才能开始找自己的萝卜。

            2. 如果有重复元素，例如：
                    nums[i]     1  2  3  2    萝卜
                        i       0  1  2  3    坑
                同样的，0号坑不要1号，先和1号坑交换，
            
                交换完这样的：
                    nums[i]     2  1  3  2    萝卜
                        i       0  1  2  3    坑
                0号坑不要2号萝卜，去和2号坑交换，
            
                交换完这样的：
                    nums[i]     3  1  2  2    萝卜
                        i       0  1  2  3    坑
                0号坑不要3号萝卜，去和3号坑交换，
            
                交换完这样的：
                    nums[i]     2  1  2  3    萝卜
                        i       0  1  2  3    坑
                0号坑不要2号萝卜，去和2号坑交换，结果发现你2号坑也是2号萝卜，那我还换个锤子，同时也说明有重复元素出现。

            来源：力扣（LeetCode）
            链接：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/solution/yuan-di-zhi-huan-shi-jian-kong-jian-100-by-derrick/705525
        """

        # swap, need mathematics prove for time o(n)
        index = 0
        while index < len(nums):
            if nums[index] != index:
                if nums[index] == nums[nums[index]]:    # duplication found
                    return nums[index]
                else:                                   # swap otherwise
                    temp = nums[index]
                    nums[index], nums[temp] = nums[temp], nums[index]
            else:
                index = index + 1
        return "no repeated item"

    # binary search, ms, mb, time o(logn), space o(1), input remains intact  
    def findRepeatNumber5(self, nums: List[int]) -> int:
        pass


if __name__ == '__main__':
    
    s = Solution()

    input = [
        [1, 2, 4, 3, 1, 5, 6],
        [2, 3, 1, 0, 2, 5, 3],
        [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 11], 
        [2, 10000, 1, 0, 2, 5, 3, 10000],
        [0, 1, 2, 3],   # no repeated data
        [0, 1, 2, 4],   # 4 > 4-1
        [1, 2, -1],     # -1 < 0
        [],             # empty
        None,           # None
    ]

    print('-----')
    for item in input:
        print(s.findRepeatNumber(item))     # hash using dict
        print(s.findRepeatNumber2(item))    # set()
        print(s.findRepeatNumber3(item))    # sort then compare
        print(s.findRepeatNumber4(item))    # pigeonhole principle
        print(s.findRepeatNumber5(item))    # binary search
        print('-----')