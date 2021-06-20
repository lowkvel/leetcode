from leetcode_originals import lc1

import unittest

class Test_twoSum(unittest.TestCase):

    def test_twoSum(self):
        s = lc1.Solution()
        self.assertEqual(s.twoSum([2,7,11,15], 9), [0,1])

    def test_twoSum2(self):
        s = lc1.Solution()
        self.assertIn(s.twoSum2([2,7,11,15], 9), [[0,1], [1,0]])


if __name__ == '__main__':
    unittest.main()
