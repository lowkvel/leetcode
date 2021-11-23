
"""
    二叉树的下一个节点

    给定一棵二叉树和其中一个节点，如何找出中序遍历序列的下一个节点？
    树中的节点除了有两个分别指向左、右节点的指针，还有一个指向父节点的指针。

    给出：
              a
            /   \
          b       c
         / \     / \
        d   e   f   g
           / \
          h   i

    返回：
        任意节点中序遍历序列的下一个节点

    限制：
        0 <= 节点个数 <= n

    来源：
    链接：
"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        self.parent = None

class Solution:

    # , ms, mb, time o(n), space o(1)
    def retrieveNextNode(self, node: TreeNode) -> TreeNode:

        # deal with empty tree
        if node is None:
            return None
        
        # if the node has left child, useless since all left subtree has been visited
        if node.left is not None:
            pass

        # if the node has right child, the next node will be the left-most node of its right subtree
        if node.right is not None:
            pointer = node.right
            while pointer.left is not None:
                pointer = pointer.left
            return pointer

        # if the node does not have right child, the next node will be the node which is its parent's left child, or None
        if node.right is None:
            pointer = node
            while pointer.parent is not None:
                if pointer == pointer.parent.left:
                    return pointer.parent
                pointer = pointer.parent
            return None

        return None


if __name__ == '__main__':

    s = Solution()

    a = TreeNode('a')
    b = TreeNode('b')
    c = TreeNode('c')
    d = TreeNode('d')
    e = TreeNode('e')
    f = TreeNode('f')
    g = TreeNode('g')
    h = TreeNode('h')
    i = TreeNode('i')

    a.left = b
    a.right = c

    b.left = d
    b.right = e
    b.parent = a

    c.left = f
    c.right = g
    c.parent = a

    d.parent = b

    e.left = h
    e.right = i
    e.parent = b

    f.parent = c

    g.parent = c

    h.parent = e
    
    i.parent = e

    input = [
        a, b, c, d, e, f, g, h, i, 
    ]

    print('-----')
    for item in input:
        if s.retrieveNextNode(item) is not None:
            print(item.val, '->', s.retrieveNextNode(item).val)
        else:
            print(item.val, '->', None)
        print('-----')