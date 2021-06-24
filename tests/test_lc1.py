from leetcode_originals import lc1

import unittest

in_out = [
        [
            [2,7,11,15], 9,
            [[0,1], [1,0]]
        ],
        [
            [3,2,4], 6,
            [[1,2], [2,1]]
        ],
        [
            [3,3], 6,
            [[0,1], [1,0]]
        ],
    ]

class Test_twoSum(unittest.TestCase):

    def test_twoSum(self):
        s = lc1.Solution()
        for items in in_out:
            self.assertIn(s.twoSum(items[0], items[1]), items[2])

    def test_twoSum2(self):
        s = lc1.Solution()
        for items in in_out:
            self.assertIn(s.twoSum(items[0], items[1]), items[2])


if __name__ == '__main__':
    unittest.main()
