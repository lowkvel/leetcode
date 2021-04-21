"""
test
"""


input = [[3,9,20,15,7], [9,3,15,20,7]]

root = -1
for index in range(0, len(input[1]), 1):
    if input[1][index] == input[0][0]:
        root = index
        break

in_left = input[1][0:root]
in_right = input[1][root+1:len(input[1])]

pre_left = input[0][1:len(in_left)+1]
pre_right = input[0][len(in_left)+1:]

print(in_left)
print(in_right)
print(pre_left)
print(pre_right)