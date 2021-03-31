# similar to 26, 283

from typing import List

class Solution:
    # brute force, 32ms, 14.9mb
    def removeElement(self, nums: List[int], val: int) -> int:
        i = 0
        while i < len(nums):
            if nums[i] == val:
                del nums[i]
            else:
                i = i + 1
        return len(nums)

    # dual pointers, 44ms, 14.7mb
    def removeElement2(self, nums: List[int], val: int) -> int:
        if len(nums) <= 0:
            return len(nums)
        else:
            i, j = 0, 0
            while j < len(nums):
                if nums[j] != val:
                    if j != i:
                        nums[i], nums[j] = nums[j], nums[i]
                    i = i + 1
                j = j + 1
            return i


if __name__ == '__main__':

    s = Solution()

    nums = [
        [[3,2,2,3], 3],
        [[0,1,2,2,3,0,4,2], 2],
    ]

    for item in nums:
        #print(s.removeElement(item[0], item[1]), item[0])
        print(s.removeElement2(item[0], item[1]), item[0])