# similar to 26, 27

from typing import List

class Solution:
    # brute force, 36ms, 15.3mb
    def moveZeroes(self, nums: List[int]) -> None:
        i = 0   # pointer
        c = 0   # count for 0
        while i < len(nums):
            if nums[i] == 0:
                del nums[i]
                c = c + 1
            else:
                i = i + 1
        
        for i in range(0, c, 1):
            nums.append(0)

    # dual pointers, 44ms, 15.3mb
    def moveZeroes2(self, nums: List[int]) -> None:
        if len(nums) == 0:
            return
        else:
            # use i to mark the first 0 element and use j to mark the first none-0 element, then swapping until j reaches the end of list
            i = 0   # pointer for 0 element
            j = 0   # pointer for none-0 element
            while j < len(nums):
                if nums[j] != 0:
                    if j != i:
                        nums[i], nums[j] = nums[j], nums[i]
                        i = i + 1
                    else:
                        i = i + 1
                j = j + 1


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