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