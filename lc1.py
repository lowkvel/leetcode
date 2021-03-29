from typing import List

class Solution:
    def twoSum(self, nums:List[int], target:int) -> List[int]:
        for i in range(0, len(nums)-1, 1):
            for j in range(i+1, len(nums), 1):
                if nums[j] == target - nums[i]:
                    return [i, j]


if __name__ == '__main__':

    s = Solution()

    nums1 = [2,7,11,15]
    target1 = 9
    print(s.twoSum(nums1, target1))

    nums2 = [3,2,4]
    target2 = 6
    print(s.twoSum(nums2, target2))

    nums3 = [3,3]
    target3 = 6
    print(s.twoSum(nums3, target3))


