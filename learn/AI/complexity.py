def depth(input):
    if not isinstance(input, tuple):
        return 0
    return max(depth(input[1]), depth(input[2])) + 1


if __name__ == '__main__':

    print(depth('x'))
    tup = ('/', 'x', 2)
    tup2 = ('/', ('expt', 'x', 5), ('expt', ('-', ('expt', 'x', 2), 1), ('/', 5, 2)))

    print(depth(tup2))
 
