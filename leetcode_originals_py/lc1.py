from typing import List

class Solution:

    # brute force, O(n^2), 44ms, 14.9mb
    def twoSum(self, nums:List[int], target:int) -> List[int]:
        for i in range(0, len(nums)-1, 1):
            for j in range(i+1, len(nums), 1):
                if nums[j] == target - nums[i]:
                    return [i, j]

    # dict, O(n), 36ms, 14.9mb
    def twoSum2(self, nums:List[int], target:int) -> List[int]:
        d = {}
        for i in range(0, len(nums), 1):
            if target-nums[i] in d and i != d[target-nums[i]][1]:
                return [i, d[target-nums[i]][1]]
            d[nums[i]] = [nums[i], i]
        return [0, 0]

if __name__ == '__main__':

    s = Solution()

    nt = [
        [[2,7,11,15], 9],
        [[3,2,4], 6],
        [[3,3], 6],
    ]

    for i in range(0, len(nt), 1):
        print(s.twoSum(nt[i][0], nt[i][1]))
        print(s.twoSum2(nt[i][0], nt[i][1]))




