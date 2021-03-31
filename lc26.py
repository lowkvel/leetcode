from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 0
        while i < len(nums) - 1:
            if nums[i] == nums[i+1]:
                del nums[i]
            else:
                i = i + 1
        return len(nums)
        


if __name__ == '__main__':
    
    s = Solution()

    nums = [
        [1,1,2],
        [0,0,1,1,1,2,2,3,3,4],]

    for item in nums:
        print(s.removeDuplicates(item), item)
