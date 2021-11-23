from typing import List

class Solution:
    # brute force, O(n^2), maximum time exceeded
    def maxSubArray(self, nums: List[int]) -> int:
        count = 0

        if len(nums) == 0:
            return 0
        else:
            count = nums[0]

        for i in range(0, len(nums), 1):
            temp = 0
            for j in range(i, len(nums), 1):
                temp = temp + nums[j]
                if temp > count:
                    count = temp
        return count

    def maxSubArray2(self, nums: List[int]) -> int:
        count = 0
        
        if len(nums) == 0:
            return 0
        else:
            count = nums[0]

        

if __name__ == '__main__':

    s = Solution()

    nums = [
        [-2,1,-3,4,-1,2,1,-5,4],
        [1],
        [5,4,-1,7,8],
    ]

    for item in nums:
        print(s.maxSubArray(item))
        print(s.maxSubArray2(item))
        print('-----')