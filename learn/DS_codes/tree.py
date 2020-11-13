class Tree:

    def root(self):
        raise NotImplementedError('must be implemented by subclass')
    def parent(self, p):
        raise NotImplementedError('must be implemented by subclass')
    def element(self, p):
        raise NotImplementedError('must be implemented by subclass')
    def left_most_child(self, p):
        raise NotImplementedError('must be implemented by subclass')
    def rigt_most_child(self, p):
        raise NotImplementedError('must be implemented by subclass')
    def right_sibling(self, p):
        raise NotImplementedError('must be implemented by subclass')
    def __len__(self):
        raise NotImplementedError('must be implemented by subclass')
    def is_node(self, p):
        raise NotImplementedError('must be implemented by subclass')