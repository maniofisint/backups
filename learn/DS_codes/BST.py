class BST:
    class Node:
        def __init__(self, key, left, right, parent = None):
            self.key = key
            self.left = left
            self.right = right
            self.parent = parent

    def __init__(self):
        self.root = None
        self.size = 0

    def _inorder(self, p):
        if p is None:
            return
        self._inorder(p.left)
        print(p.key, end=' ')
        self._inorder(p.right)
        
    def subtree_search(self, r, x):
        if r is None or r.key == x:
            return r

        if x < r.key:
            return self.subtree_search(r.left, x)
        else:
            return self.subtree_search(r.right, x)

    def nr_subtree_search(self, r, x):
        while r is not None and not r.key == x:
            if x < r.key:
                r = r.left
            else:
                r = r.right
        return r

    def find_min(self, r):
        if r.left is None:
            return r
        return self.find_min(r.left)

    def nr_find_min(self, r):
        while r.left is not None:
            r = r.left
        return r

    def find_successor(self, r):
        if r.right is not None:
            return self.find_min(r.right)

        y = r.parent
        while y is not None and r == y.right:
            r = y
            y = r.parent
        return y

    def insert(self, r, x):
        if x < r.key:
            if r.left is None:
                r.left = self.Node(x, None, None, r)
            else:
                self.insert(r.left, x)
        elif x > r.key:
            if r.right is None:
                r.right = self.Node(x, None, None, r)
            else:
                self.insert(r.right, x)


    def nr_insert(self, x):
        prep = None
        p = self.root
        while p is not None:
            prep = p

            if x < p.key:
                p = p.left
            elif x > p.key:
                p = p.right
            else:
                return

            new_node = self.Node(x, None, None, prep)
            if prep is None:
                self.root = new_node
            elif x < prep.key:
                prep.left = new_node
            else:
                prep.right = new_node

    def is_empty(self):
        return self.size == 0

    def delete_min(self, r):
        if self.is_empty():
            raise Exception('BST is empty')

        r = self.find_min(r)
        self.replace(r, r.right)
        self.size -= 1
        return r.key

    def replace(self, r, child):
        if r == self.root:
            self.root = child
        elif r == r.parent.left:
            r.parent.left = child
        else:
            r.parent.right = child

        if child is not None:
            child.parent = r.parent

    def delete(self, r, x):
        if r is None:
            return

        if x < r.key:
            self.delete(r.left, x)

        if x > r.key:
            self.delete(r.right, x)

        if x == r.key:
            if r.left is None:
                self.replace(r, r.right)
            if r.right is None:
                self.replace(r, r.left)
            else:
                r.key = self.delete_min(r.right)
                 