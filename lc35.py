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