# similar to 27, 283

from typing import List

class Solution:
    # brute force, 60ms, 15.9mb
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 0
        while i < len(nums) - 1:
            if nums[i] == nums[i+1]:
                del nums[i]
            else:
                i = i + 1
        return len(nums)
        
    # dual pointers, 40ms, 15.8mb
    def removeDuplicates2(self, nums: List[int]) -> int:
        if len(nums) <= 1:
            return len(nums)
        else:
            i, j = 0, 1
            while j < len(nums):
                if nums[i] == nums[j]:
                    j = j + 1
                else:
                    i = i + 1
                    nums[i] = nums[j]
                    j = j + 1
            return i + 1


if __name__ == '__main__':
    
    s = Solution()

    nums = [
        [1,1,2],
        [0,0,1,1,1,2,2,3,3,4],]

    for item in nums:
        #print(s.removeDuplicates(item), item)
        print(s.removeDuplicates2(item), item)
