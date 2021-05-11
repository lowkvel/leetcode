from typing import List

# same question as lc154
"""
    旋转数组的最小数字

    把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
    输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
    例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  

    示例 1：
        输入：[3,4,5,1,2]
        输出：1
    
    示例 2：
        输入：[2,2,2,0,1]
        输出：0

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

class Solution:

    # simple, 36ms, 15.1mb, time o(n), space o(1)
    def minArray(self, numbers: List[int]) -> int:

        # edge case, empty list or list with no element
        if numbers is None or len(numbers) == 0:
            return None

        # edge case, list with only one element
        if len(numbers) == 1:
            return numbers[0]

        for index in range(0, len(numbers) - 1, 1):
            if numbers[index] > numbers[index + 1]:
                return numbers[index + 1]
        return numbers[0]

    # binary search, 44ms, 15.1mb, time o(nlogn) - o(n), space o(1)
    def minArray2(self, numbers: List[int]) -> int:

        # edge case, empty list or list with no element
        if numbers is None or len(numbers) == 0:
            return None

        low = 0
        high = len(numbers) - 1
        while low < high:
            pivot = low + (high - low) // 2

            if numbers[pivot] < numbers[high]:      # numbers[pivot] < numbers[high]
                high = pivot
            elif numbers[pivot] > numbers[high]:    # numbers[pivot] > numbers[high]
                low = pivot + 1
            elif numbers[pivot] == numbers[high]:   # numbers[pivot] == numbers[high]
                high = high - 1

        return numbers[low]




if __name__ == '__main__':

    s = Solution()

    input = [
        #[3,4,5,1,2],
        #[2,2,2,0,1],

        [3,1,3],
    ]

    print('-----')
    for item in input:
        print(s.minArray(item))
        print(s.minArray2(item))

        print('-----')

