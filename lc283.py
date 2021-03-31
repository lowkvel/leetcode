# similar to 26, 27

from typing import List

class Solution:
    # brute force, 36ms, 15.3mb
    def moveZeroes(self, nums: List[int]) -> None:
        i, c = 0, 0
        while i < len(nums):
            if nums[i] == 0:
                del nums[i]
                c = c + 1
            else:
                i = i + 1
        
        for i in range(0, c, 1):
            nums.append(0)


if __name__ == '__main__':

    s = Solution()

    nums = [
        [0],
        [0,1,0,3,12],
    ]

    for item in nums:
        #s.moveZeroes(item)
        s.moveZeroes2(item)
        print(item)