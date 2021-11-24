"""
    替换空格

    请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

    示例 1：
        输入：s = "We are happy."
        输出："We%20are%20happy."
 
    限制:
        0 <= s 的长度 <= 10000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

class Solution:

    # python str.replace(), 36ms, 14.8mb, input remains intact
    def replaceSpace(self, s: str) -> str:

        # check for invalid input
        if s is None:
            return 'invalid input'
        
        # python str.replace()
        return s.replace(' ', '%20')

    # replace from head, 24ms, 14.9mb, time o(n^2), space o(1), input changes
    def replaceSpace2(self, s: str) -> str:

        # check for invalid input
        if s is None:
            return 'invalid input'

        # replace from head
        index = 0
        while index < len(s):
            if s[index] == ' ':
                s = s[0:index] + '%20' + s[index + 1:len(s)]
                index = index + 3
                continue
            index = index + 1
        return s

    # replace backwards, ms, mb, time o(n), space o(1), input changes
    def replaceSpace3(self, s: str) -> str:
        
        # check for invalid input
        if s is None:
            return 'invalid input'

        # count for spaces
        space_count = 0
        for index in range(0, len(s), 1):
            if s[index] == ' ':
                space_count = space_count + 1
        
        # replace backwards
        return('need implementation')


if __name__ == '__main__':

    s = Solution()

    input = [
        'We are happy.',    # normal input

        '  ',               # only spaces exists
        ' asdfasdf',        # head spaces
        'asdfafd ',         # tail spaces
        'asdf  asdf',       # multiple spaces
        'asdfasdf',         # no space exists
        '',                 # empty string
        None,               # None
    ]

    print('-----')
    for item in input:
        print(s.replaceSpace(item))     # python str.replace()
        print(s.replaceSpace2(item))    # replace from head
        print(s.replaceSpace3(item))    # replace backwards
        print('-----')
