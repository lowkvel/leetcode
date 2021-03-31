class Solution:

    # brute force, 48ms, 14.9mb
    def reverseBits(self, n:int) -> int:
        return int('{:0>32b}'.format(n)[::-1], 2)


if __name__ == '__main__':

    s = Solution()

    n = [
        0b00000010100101000001111010011100,
        0b11111111111111111111111111111101,
    ]

    for i in range(0, len(n), 1):
        print('{:0>32b}'.format(n[i]))
        print('{:0>32b}'.format(n[i])[::-1])
        print(s.reverseBits(n[i]))






