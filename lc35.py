from typing import List

class Solution:
    
    # brute force, 44ms, 15.2mb
    def searchInsert(self, nums: List[int], target: int) -> int:
        for i in range(0, len(nums), 1):
            if nums[i] == target:
                return i
            elif nums[i] > target:
                return i
        return len(nums)
        
    # binary search, 44ms, 15.3mb
    def searchInsert2(self, nums: List[int], target: int) -> int:
        low, high = 0, len(nums) - 1
        while low <= high:
            mid = low + round((high - low) / 2)
            if nums[mid] >= target:
                high = mid - 1
            else:
                if mid == len(nums) - 1 or nums[mid+1] >= target:
                    return mid + 1
                low = mid + 1
        return 0
                
    """
    二分查找法：
        分析题意，挖掘隐含的单调性；
            while (left < right) 退出循环的时候有 left == right 成立，因此无需考虑返回 left 还是 right；
        始终思考下一轮搜索区间是什么，
            如果是 [mid, right] 就对应 left = mid ，
            如果是 [left, mid - 1] 就对应 right = mid - 1，
            是保留 mid 还是+1、−1就在这样的思考中完成；
        从一个元素什么时候不是解开始考虑下一轮搜索区间是什么 ，把区间分为 2 个部分（一个部分肯定不存在目标元素，另一个部分有可能存在目标元素）；
            每一轮区间被划分成 2 部分，理解 区间划分 决定中间数取法，在调试的过程中理解 区间和中间数划分的配对关系：
                划分 [left, mid] 与 [mid + 1, right] ，mid 被分到左边，对应 int mid = left + (right - left) / 2;；
                划分 [left, mid - 1] 与 [mid, right] ，mid 被分到右边，对应 int mid = left + (right - left + 1) / 2;。
            至于为什么划分是这种对应关系，原因在于区间只有 2 个数的时候，如果中间数的取法不对，一旦进入的分支不能使得区间缩小，会出现死循环；
        退出循环的时候有 left == right 成立，此时如果能确定问题一定有解，返回 left 即可，如果不能确定，需要单独判断一次。
        
    作者：liweiwei1419
    链接：https://leetcode-cn.com/problems/search-insert-position/solution/te-bie-hao-yong-de-er-fen-cha-fa-fa-mo-ban-python-/
    来源：力扣（LeetCode）
    """

    # binary search, 32ms, 15.3mb
    def searchInsert3(self, nums: List[int], target: int) -> int:

        # check for empty list
        if len(nums) == 0:
            return 0

        # check for tail item
        if nums[len(nums) - 1] < target:
            return len(nums)

        left, right = 0, len(nums) - 1  # search range initiation = [0, len(nums) - 1]
        while left < right:
            mid = (left + right) // 2   # mid calculation, round down integer division using //, ex: 2.5 --> 2
            if nums[mid] <  target:
                left = mid + 1          # next search range = [mid + 1, right]
            else:
                right = mid             # next search range = [left, mid]
        return left

    # binary search, 60ms, 15.2mb
    def searchInsert4(self, nums: List[int], target: int) -> int:

        # check for empty list
        if len(nums) == 0:
            return 0

        left, right = 0, len(nums)      # search range initiation = [0, len(nums)]
        while left < right:
            mid = (left + right) // 2   # mid calculation, round down integer division using //, ex: 2.5 --> 2
            if nums[mid] <  target:
                left = mid + 1          # next search range = [mid + 1, right]
            else:
                right = mid             # next search range = [left, mid]
        return left


if __name__ == '__main__':
     
    s = Solution()

    nums = [
        [[1,3,5,6], 5],
        [[1,3,5,6], 2],
        [[1,3,5,6], 7],
        [[1,3,5,6], 0],
        [[1], 0],
    ]

    for item in nums:
        print(s.searchInsert(item[0], item[1]))
        print(s.searchInsert2(item[0], item[1]))
        print(s.searchInsert3(item[0], item[1]))    # *
        print(s.searchInsert4(item[0], item[1]))
        print('-----')