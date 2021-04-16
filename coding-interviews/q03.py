from typing import List

"""
找出数组中重复的数字。

在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

输入：[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3

限制：2 <= n <= 100000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

class Solution:

    # dict, 72ms, 23.4mb, 时间o(n), 空间o(n)
    def findRepeatNumber(self, nums: List[int]) -> int:

        # check for invalid input
        if nums is None:
            return "invalid input"

        for item in nums:
            if item > len(nums)-1 or item < 0:
                return "invalid input"

        # hash
        d = {}
        for item in nums:
            if item in d:
                return item
            else:
                d[item] = item
        return "no repeated item"

    # sort, 88ms, 23.4mb, 时间o(nlogn), 空间o(1)    
    def findRepeatNumber2(self, nums: List[int]) -> int:

        # check for invalid input
        if nums is None:
            return "invalid input"

        for item in nums:
            if item > len(nums)-1 or item < 0:
                return "invalid input"

        # sort
        nums.sort()
        for index in range(0, len(nums)-1, 1):
            if nums[index] == nums[index + 1]:
                return nums[index]
        return "no repeated item"

    # Pigeonhole principle, ms, mb, 时间o(n), 空间o(1)    
    def findRepeatNumber3(self, nums: List[int]) -> int:
        pass




if __name__ == '__main__':
    
    s = Solution()

    nums = [
        [2, 3, 1, 0, 2, 5, 3],

        [0, 1, 2, 3],   # no repeated data
        [0, 1, 2, 4],   # 4 > 4-1
        [1, 2, -1],     # -1 < 0
        [],             # empty
        None,           # None
    ]

    print('-----')
    for item in nums:
        print(s.findRepeatNumber(item))
        print(s.findRepeatNumber2(item))
        #print(s.findRepeatNumber3(item))
        print('-----')

