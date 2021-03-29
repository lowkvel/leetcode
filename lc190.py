class Solution:
    def reverseBits(self, n:int) -> int:
        return int('{:0>32b}'.format(n)[::-1], 2)


if __name__ == '__main__':

    s = Solution()

    n1 = 0b00000010100101000001111010011100
    print('{:0>32b}'.format(n1))
    print('{:0>32b}'.format(n1)[::-1])
    print(s.reverseBits(n1))

    n2 = 0b11111111111111111111111111111101
    print('{:0>32b}'.format(n2))
    print('{:0>32b}'.format(n2)[::-1])
    print(s.reverseBits(n2))





